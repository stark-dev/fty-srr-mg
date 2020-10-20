/*  =========================================================================
    fty_srr_worker - Fty srr worker

    Copyright (C) 2014 - 2020 Eaton

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
    =========================================================================
*/

#pragma once

#include "fty-srr.h"

#include <map>
#include <string>
#include <vector>

namespace srr
{
std::string getGroupFromFeature(const std::string& featureName);
unsigned int getPriority(const std::string& featureName);

typedef struct SrrFeatureStruct
{
    std::string m_id;
    std::string m_name;
    std::string m_description;

    std::string m_agent;

    bool m_restart;
} SrrFeatureStruct;

typedef struct SrrFeaturePriorityStruct
{
    SrrFeaturePriorityStruct(const std::string& f, unsigned int p) : m_feature(f), m_priority(p) {};
    std::string m_feature;
    unsigned int m_priority;
} SrrFeaturePriorityStruct;

typedef struct SrrGroupStruct
{
    std::string m_id;
    std::string m_name;
    std::string m_description;

    std::vector<SrrFeaturePriorityStruct> m_fp;
} SrrGroupStruct;

auto initSrrFeatures = [&]() {
    std::map<std::string, SrrFeatureStruct> tmp;

    tmp[F_ALERT_AGENT];
    tmp[F_ALERT_AGENT].m_id = F_ALERT_AGENT;
    tmp[F_ALERT_AGENT].m_name = F_ALERT_AGENT;
    tmp[F_ALERT_AGENT].m_description = std::string(SRR_PREFIX_TRANSLATE_KEY) + F_ALERT_AGENT;
    tmp[F_ALERT_AGENT].m_agent = ALERT_AGENT_NAME;
    tmp[F_ALERT_AGENT].m_restart = true;

    tmp[F_ASSET_AGENT];
    tmp[F_ASSET_AGENT].m_id = F_ASSET_AGENT;
    tmp[F_ASSET_AGENT].m_name = F_ASSET_AGENT;
    tmp[F_ASSET_AGENT].m_description = std::string(SRR_PREFIX_TRANSLATE_KEY) + F_ASSET_AGENT;
    tmp[F_ASSET_AGENT].m_agent = ASSET_AGENT_NAME;
    tmp[F_ASSET_AGENT].m_restart = true;

    tmp[F_AUTOMATION_SETTINGS];
    tmp[F_AUTOMATION_SETTINGS].m_id = F_AUTOMATION_SETTINGS;
    tmp[F_AUTOMATION_SETTINGS].m_name = F_AUTOMATION_SETTINGS;
    tmp[F_AUTOMATION_SETTINGS].m_description = std::string(SRR_PREFIX_TRANSLATE_KEY) + F_AUTOMATION_SETTINGS;
    tmp[F_AUTOMATION_SETTINGS].m_agent = CONFIG_AGENT_NAME;
    tmp[F_AUTOMATION_SETTINGS].m_restart = true;

    tmp[F_AUTOMATIONS];
    tmp[F_AUTOMATIONS].m_id = F_AUTOMATIONS;
    tmp[F_AUTOMATIONS].m_name = F_AUTOMATIONS;
    tmp[F_AUTOMATIONS].m_description = std::string(SRR_PREFIX_TRANSLATE_KEY) + F_AUTOMATIONS;
    tmp[F_AUTOMATIONS].m_agent = EMC4J_AGENT_NAME;
    tmp[F_AUTOMATIONS].m_restart = true;

    tmp[F_DISCOVERY];
    tmp[F_DISCOVERY].m_id = F_DISCOVERY;
    tmp[F_DISCOVERY].m_name = F_DISCOVERY;
    tmp[F_DISCOVERY].m_description = std::string(SRR_PREFIX_TRANSLATE_KEY) + F_DISCOVERY;
    tmp[F_DISCOVERY].m_agent = CONFIG_AGENT_NAME;
    tmp[F_DISCOVERY].m_restart = true;

    tmp[F_MASS_MANAGEMENT];
    tmp[F_MASS_MANAGEMENT].m_id = F_MASS_MANAGEMENT;
    tmp[F_MASS_MANAGEMENT].m_name = F_MASS_MANAGEMENT;
    tmp[F_MASS_MANAGEMENT].m_description = std::string(SRR_PREFIX_TRANSLATE_KEY) + F_MASS_MANAGEMENT;
    tmp[F_MASS_MANAGEMENT].m_agent = CONFIG_AGENT_NAME;
    tmp[F_MASS_MANAGEMENT].m_restart = true;

    tmp[F_MONITORING_FEATURE_NAME];
    tmp[F_MONITORING_FEATURE_NAME].m_id = F_MONITORING_FEATURE_NAME;
    tmp[F_MONITORING_FEATURE_NAME].m_name = F_MONITORING_FEATURE_NAME;
    tmp[F_MONITORING_FEATURE_NAME].m_description = std::string(SRR_PREFIX_TRANSLATE_KEY) + F_MONITORING_FEATURE_NAME;
    tmp[F_MONITORING_FEATURE_NAME].m_agent = CONFIG_AGENT_NAME;
    tmp[F_MONITORING_FEATURE_NAME].m_restart = true;

    tmp[F_NETWORK];
    tmp[F_NETWORK].m_id = F_NETWORK;
    tmp[F_NETWORK].m_name = F_NETWORK;
    tmp[F_NETWORK].m_description = std::string(SRR_PREFIX_TRANSLATE_KEY) + F_NETWORK;
    tmp[F_NETWORK].m_agent = CONFIG_AGENT_NAME;
    tmp[F_NETWORK].m_restart = true;

    tmp[F_NOTIFICATION_FEATURE_NAME];
    tmp[F_NOTIFICATION_FEATURE_NAME].m_id = F_NOTIFICATION_FEATURE_NAME;
    tmp[F_NOTIFICATION_FEATURE_NAME].m_name = F_NOTIFICATION_FEATURE_NAME;
    tmp[F_NOTIFICATION_FEATURE_NAME].m_description = std::string(SRR_PREFIX_TRANSLATE_KEY) + F_NOTIFICATION_FEATURE_NAME;
    tmp[F_NOTIFICATION_FEATURE_NAME].m_agent = CONFIG_AGENT_NAME;
    tmp[F_NOTIFICATION_FEATURE_NAME].m_restart = true;


    tmp[F_SECURITY_WALLET];
    tmp[F_SECURITY_WALLET].m_id = F_SECURITY_WALLET;
    tmp[F_SECURITY_WALLET].m_name = F_SECURITY_WALLET;
    tmp[F_SECURITY_WALLET].m_description = std::string(SRR_PREFIX_TRANSLATE_KEY) + F_SECURITY_WALLET;
    tmp[F_SECURITY_WALLET].m_agent = SECU_WALLET_AGENT_NAME;
    tmp[F_SECURITY_WALLET].m_restart = true;

    tmp[F_USER_SESSION_FEATURE_NAME];
    tmp[F_USER_SESSION_FEATURE_NAME].m_id = F_USER_SESSION_FEATURE_NAME;
    tmp[F_USER_SESSION_FEATURE_NAME].m_name = F_USER_SESSION_FEATURE_NAME;
    tmp[F_USER_SESSION_FEATURE_NAME].m_description = std::string(SRR_PREFIX_TRANSLATE_KEY) + F_USER_SESSION_FEATURE_NAME;
    tmp[F_USER_SESSION_FEATURE_NAME].m_agent = CONFIG_AGENT_NAME;
    tmp[F_USER_SESSION_FEATURE_NAME].m_restart = true;

    tmp[F_VIRTUAL_ASSETS];
    tmp[F_VIRTUAL_ASSETS].m_id = F_VIRTUAL_ASSETS;
    tmp[F_VIRTUAL_ASSETS].m_name = F_VIRTUAL_ASSETS;
    tmp[F_VIRTUAL_ASSETS].m_description = std::string(SRR_PREFIX_TRANSLATE_KEY) + F_VIRTUAL_ASSETS;
    tmp[F_VIRTUAL_ASSETS].m_agent = EMC4J_AGENT_NAME;
    tmp[F_VIRTUAL_ASSETS].m_restart = true;

    return tmp;
};

static const std::map<std::string, SrrFeatureStruct> SrrFeatureMap = initSrrFeatures();

auto initSrrGroups = [&]() {

    std::map<std::string, SrrGroupStruct> tmp;

    // assets-group
    tmp[G_ASSETS];
    
    tmp[G_ASSETS].m_id = G_ASSETS,
    tmp[G_ASSETS].m_name = G_ASSETS,
    tmp[G_ASSETS].m_description = G_ASSETS,

    tmp[G_ASSETS].m_fp.push_back(SrrFeaturePriorityStruct(F_ASSET_AGENT, 1));
    // tmp[G_ASSETS].m_fp.push_back(SrrFeaturePriorityStruct(F_VIRTUAL_ASSETS, 2));

    // config-group
    tmp[G_CONFIG];
    tmp[G_CONFIG].m_id = G_CONFIG;
    tmp[G_CONFIG].m_name = G_CONFIG;
    tmp[G_CONFIG].m_description = G_CONFIG;

    tmp[G_CONFIG].m_fp.push_back(SrrFeaturePriorityStruct(F_AUTOMATION_SETTINGS       , 1));
    tmp[G_CONFIG].m_fp.push_back(SrrFeaturePriorityStruct(F_DISCOVERY                 , 2));
    tmp[G_CONFIG].m_fp.push_back(SrrFeaturePriorityStruct(F_MASS_MANAGEMENT           , 2));
    tmp[G_CONFIG].m_fp.push_back(SrrFeaturePriorityStruct(F_MONITORING_FEATURE_NAME   , 3));
    // tmp[G_CONFIG].m_fp.push_back(SrrFeaturePriorityStruct(F_NETWORK                   , 4));
    tmp[G_CONFIG].m_fp.push_back(SrrFeaturePriorityStruct(F_NOTIFICATION_FEATURE_NAME , 5));
    tmp[G_CONFIG].m_fp.push_back(SrrFeaturePriorityStruct(F_USER_SESSION_FEATURE_NAME , 6));

    // security-wallet
    tmp[G_SECW];
    tmp[G_SECW].m_id = G_SECW;
    tmp[G_SECW].m_name = G_SECW;
    tmp[G_SECW].m_description = G_SECW;

    tmp[G_SECW].m_fp.push_back(SrrFeaturePriorityStruct(F_SECURITY_WALLET, 1));

    return tmp;
};

static const std::map<std::string, SrrGroupStruct> SrrGroupMap = initSrrGroups();

static std::map<const std::string, const std::string> agentToQueue = {
    { ALERT_AGENT_NAME      , ALERT_AGENT_MSG_QUEUE_NAME },
    { ASSET_AGENT_NAME      , ASSET_AGENT_MSG_QUEUE_NAME },
    { CONFIG_AGENT_NAME     , CONFIG_MSG_QUEUE_NAME },
    { EMC4J_AGENT_NAME      , EMC4J_MSG_QUEUE_NAME },
    { SECU_WALLET_AGENT_NAME, SECU_WALLET_MSG_QUEUE_NAME }
};

}