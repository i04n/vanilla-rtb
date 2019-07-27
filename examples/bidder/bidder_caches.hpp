/* 
 * File:   bidder_caches.hpp
 * Author: arseny.bushev@gmail.com
 *
 * Created on 16 февраля 2017 г., 21:15
 */

#ifndef BIDDER_CACHES_HPP
#define BIDDER_CACHES_HPP

#include "examples/matchers/ad.hpp"
#include "examples/matchers/geo.hpp"
#include "examples/matchers/geo_campaign.hpp"
#include "rtb/core/openrtb.hpp"
#include "rtb/common/perf_timer.hpp"
#include "examples/campaign/campaign_cache.hpp"

namespace vanilla {
template<typename Config = BidderConfig>
struct BidderCaches {
    public:
        BidderCaches(const Config &config):
            config(config),
            ad_data_entity(config),
            geo_data_entity(config), 
            geo_campaign_entity(config),
            budget_cache(config)
        {}        
        void load() noexcept(false) {
            auto sp = std::make_shared<std::stringstream>();
            {
                perf_timer<std::stringstream> timer(sp, "\nselector load");
                {
                    perf_timer<std::stringstream> timer(sp, "\nad load");
                    ad_data_entity.load();
                }
                {
                   perf_timer<std::stringstream> timer(sp, "\ngeo_data load");
                    geo_data_entity.load();
                }
                {
                   perf_timer<std::stringstream> timer(sp, "\ngeo_campaign load");
                   geo_campaign_entity.load();
                }
                {
                   perf_timer<std::stringstream> timer(sp, "\nbudget_cache load");
                   budget_cache.load();
                }
                // load others
            }
            LOG(info) << sp->str() ;
        }
        const Config &config;
        AdDataEntity<Config> ad_data_entity;
        GeoDataEntity<Config> geo_data_entity;
        GeoCampaignEntity<Config> geo_campaign_entity;
        vanilla::CampaignCache<Config> budget_cache;
};
}

#endif /* BIDDER_CACHES_HPP */

