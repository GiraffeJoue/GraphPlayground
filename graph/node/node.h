/* 
 * File:   node.h
 * Author: Kyle McGrath
 *
 * Created on October 12, 2017, 7:18 PM
 */

#ifndef NODE_H
#define NODE_H
#include <string>
#include <functional>
#include <memory>
#include <vector>

#define FIRST_ID "AAAAA"

class node {
    
public:
    
    typedef std::vector<node>::size_type size_type;
    
    node(int value);
    node(const node& orig);
    virtual ~node(){};
    
    static size_t hash(const node& n);
    static bool equals(const node& n1, const node& n2);
    bool operator==(const node& other);
    bool operator!=(const node& other);
    bool operator<(const node& other);
    bool operator>(const node& other);
    bool operator>=(const node& other);
    bool operator<=(const node& other);
    
    void connect(std::shared_ptr<node> n);
    node::size_type degree();
    
    std::string to_string();
    
    static void resetId();
    
    int value;
    std::string id;
    std::vector<std::weak_ptr<node>> neighbors;
    
private:
    std::string getId();
    
};

#endif /* NODE_H */

