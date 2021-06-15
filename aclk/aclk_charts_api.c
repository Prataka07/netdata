// SPDX-License-Identifier: GPL-3.0-or-later
#include "aclk_charts_api.h"

#include "aclk_query_queue.h"

void aclk_chart_inst_update(char **payloads, size_t *payload_sizes, struct aclk_message_position *new_positions)
{
    aclk_query_t query = aclk_query_new(CHART_DIMS_UPDATE_BIN);
    query->data.bin_payload.payload = generate_charts_updated(&query->data.bin_payload.size, payloads, payload_sizes, new_positions);
    if (query->data.bin_payload.payload)
        aclk_queue_query(query);
}

void aclk_chart_dim_update(char **payloads, size_t *payload_sizes, struct aclk_message_position *new_positions)
{
    aclk_query_t query = aclk_query_new(CHART_DIMS_UPDATE_BIN);
    query->data.bin_payload.payload = generate_chart_dimensions_updated(&query->data.bin_payload.size, payloads, payload_sizes, new_positions);
    if (query->data.bin_payload.payload)
        aclk_queue_query(query);
}

void aclk_chart_config_updated(struct chart_config_updated *config_list, int list_size)
{
    aclk_query_t query = aclk_query_new(CHART_CONFIG_UPDATED);
    query->data.bin_payload.payload = generate_chart_configs_updated(&query->data.bin_payload.size, config_list, list_size);
    if (query->data.bin_payload.payload)
        aclk_queue_query(query);
}

void aclk_chart_reset(chart_reset_t reset)
{
    aclk_query_t query = aclk_query_new(CHART_RESET);
    query->data.bin_payload.payload = generate_reset_chart_messages(&query->data.bin_payload.size, reset);
    if (query->data.bin_payload.payload)
        aclk_queue_query(query);
}

void aclk_chart_inst_and_dim_update(char **payloads, size_t *payload_sizes, int *is_dim, struct aclk_message_position *new_positions)
{
    aclk_query_t query = aclk_query_new(CHART_DIMS_UPDATE_BIN);
    query->data.bin_payload.payload = generate_charts_and_dimensions_updated(&query->data.bin_payload.size, payloads, payload_sizes, is_dim, new_positions);
    if (query->data.bin_payload.payload)
        aclk_queue_query(query);
}

void aclk_update_node_info(struct update_node_info *info)
{
    aclk_query_t query = aclk_query_new(UPDATE_NODE_INFO);
    query->data.bin_payload.topic = ACLK_TOPICID_NODE_CONN; //TODO waiting topic from cloud
    query->data.bin_payload.payload = generate_update_node_info_message(&query->data.bin_payload.size, info);
    if (query->data.bin_payload.payload)
        aclk_queue_query(query);
}