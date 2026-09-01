#ifndef RESOURCE_H
#define RESOURCE_H

#include <string>
#include <string_view>

/**
 * @brief Abstract base class representing a resource used in executable tasks or processes
 *
 * This class defines the interface for resources that can be allocated, release, and user
 */
class Resource {

public:
    enum class Type {Consumable, usable };

protected:
    std::string name;
    bool isAvailable;
    Type resourceType;

public:
    Resource(std::string_view name,  Type type);
    virtual ~Resource() = default;
    [[nodiscard]] std::string_view getName() const;
    [[nodiscard]] virtual bool isAvailable() const ;
    virtual void allocate() = 0;
    virtual void release() = 0;
    virtual void use() const = 0;

    [[nodiscard]] virtual std::string describeUsage() const = 0;
    [[nodiscard]] Type getResourceType() const;
};

#endif //RESOURCE_H
