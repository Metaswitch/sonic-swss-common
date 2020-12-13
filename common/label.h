#ifndef __LABEL__
#define __LABEL__

#include <stdint.h>
#include <set>
#include <string>
#include "tokenize.h"

namespace swss {

typedef uint32_t Label;

#define LABEL_DELIMITER '/'

class LabelStack
{
public:
    LabelStack() = default;
    // A list of Labels separated by '/'
    LabelStack(const std::string &str)
    {
        auto labels = swss::tokenize(str, LABEL_DELIMITER);
        for (const auto &i : labels)
            m_labelstack.insert(stoi(i));
    }

    inline const std::set<Label> &getLabelStack() const
    {
        return m_labelstack;
    }

    inline size_t getSize() const
    {
        return m_labelstack.size();
    }

    inline bool empty() const
    {
        return m_labelstack.empty();
    }

    inline bool operator<(const LabelStack &o) const
    {
        return m_labelstack < o.m_labelstack;
    }

    inline bool operator==(const LabelStack &o) const
    {
        return m_labelstack == o.m_labelstack;
    }

    inline bool operator!=(const LabelStack &o) const
    {
        return !(*this == o);
    }

    const std::string to_string() const
    {
        string str;
        for (auto it = m_labelstack.begin(); it != m_labelstack.end(); ++it)
        {
            if (it != m_labelstack.begin())
            {
                str += LABEL_DELIMITER;
            }
            str += std::to_string(*it);
        }
        return str;
    }

private:
    std::set<Label> m_labelstack;
};

}

#endif /* __LABEL__ */
