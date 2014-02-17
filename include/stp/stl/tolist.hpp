#ifndef STP_TOLIST_HPP
#define STP_TOLIST_HPP

#include <utility>
#include <list>
#include <algorithm>

namespace stp
{
    namespace detail
    {
        struct tolist_type
        {
            template
            <
                typename Input,
                typename ValueType = typename Input::value_type
            >
            std::list<ValueType> operator()(Input input) const
            {
                std::list<ValueType> list;
                std::for_each(std::begin(input), std::end(input), [&](const ValueType &i){list.push_back(std::move(i));});
                return list;
            }
        };
    }

    detail::tolist_type ToList()
    {
        return detail::tolist_type();
    }
}

#endif