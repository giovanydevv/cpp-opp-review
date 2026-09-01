#include "Resource.h"

#include <string_view>

/**
 *
 * @param name
 * @param type
 * @return
 */
Resource::Resource(std::string_view name, Type type)
    : name(name), isAvailable(false), resourceType( type)
{}

/**
 * @brief Returns the name of the resource
 *
 * @return
 */
std::string_view Resource::getName() const {
    return name;
}

/**
 *@brief Retrieves the type of resource
 *
 * @return the type of resource (consumable or usable)
 */
Type Resource::getResourceType() const {
    return resourceType;
}
