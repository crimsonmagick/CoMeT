#ifndef __DVFS_ONDEMAND_COMET_H
#define __DVFS_ONDEMAND_COMET_H

#include <vector>
#include "dvfspolicy.h"
#include "performance_counters.h"

class DVFSOndemandComet : public DVFSPolicy {
public:
    DVFSOndemandComet(
        const PerformanceCounters *performanceCounters,
        int coreRows,
        int coreColumns,
        int minFrequency,
        int maxFrequency,
        int frequencyStepSize,
        float upThreshold,
        float downThreshold,
      float dtmCriticalTemperature,
        float dtmRecoveredTemperature);

    virtual std::vector<int> getFrequencies(const std::vector<int> &oldFrequencies,
        const std::vector<bool> &activeCores);

private:
    const PerformanceCounters *performanceCounters;
    unsigned int coreRows;
    unsigned int coreColumns;
    int minFrequency;
    int maxFrequency;
    int frequencyStepSize;
    float upThreshold;
    float downThreshold;
    float dtmCriticalTemperature;
    float dtmRecoveredTemperature;
    bool in_throttle_mode = false;

    bool throttle();
};

#endif
