//
//  Blueprint.h
//  snowcrash
//
//  Created by Zdenek Nemec on 4/3/13.
//  Copyright (c) 2013 Apiary.io. All rights reserved.
//

#ifndef SNOWCRASH_BLUEPRINT_H
#define SNOWCRASH_BLUEPRINT_H

#include <vector>
#include <string>
#include <utility>

namespace snowcrash {
    
    //
    // Generic types
    //
    
    // Name of section / element. Plain text
    typedef std::string Name;

    // Section Description. Rendered HTML from Markdown
    typedef std::string Description;
    
    // URI
    typedef std::string URI;
    
    // URI template
    typedef std::string URITemplate;
    
    // HTTP Method
    typedef std::string HTTPMethod;
    
    // Default Container for collections
    // FIXME: C++11 template aliases
    template<typename T>
    struct Collection {
        typedef std::vector<T> type;
    };
    
    //
    // API Blueprint sections
    //
    
    // Asset data
    typedef std::string Asset;

    // Metadata key-value pair, e.g. "HOST: http://acme.com"
    typedef std::pair<std::string, std::string> Metadata;

    // Header key-value pair, e.g. "Content-Type: application/json"
    typedef std::pair<std::string, std::string> Header;
    
    // Parameter
    struct Parameter {
        
        // Group Name
        Name name;
        
        // Group Description
        Description description;
        
        // TODO: type, optional, default value
    };
    
    // Payload
    struct Payload {
        
        // Group Name
        Name name;
        
        // Group Description
        Description description;
        
        // Parameters
        Collection<Parameter> parameters;
        
        // Headers
        Collection<Header> headers;
        
        // Body
        Asset body;
        
        // Schema
        Asset schema;
    };
    
    // Request
    typedef Payload Request;
    
    // Response, a payload where name is HTTP status code
    typedef Payload Response;
    
    // Method
    struct Method {
        
        // HTTP method
        HTTPMethod method;
        
        // Description
        Description description;
        
        // Parameters
        Collection<Parameter> parameters;
        
        // Headers
        Collection<Header> headers;

        // Requests
        Collection<Request> requests;
        
        // Responses
        Collection<Response> responses;
    };
    
    // Resource
    struct Resource {
        
        // URI template
        URITemplate uri;
        
        // Description
        Description description;
        
        // Parameters
        Collection<Parameter>::type parameters;
        
        // Headers
        Collection<Header>::type headers;
        
        // Methods
        Collection<Method>::type methods;
    };
    
    // Group of resources
    struct ResourceGroup {
        
        // Group Name
        Name name;
        
        // Group Description
        Description description;
        
        // Resources
        Collection<Resource>::type resources;
    };
    
    // API Blueprint
    struct Blueprint {
        
        // Metadata
        Collection<Metadata>::type metadata;
        
        // API Name
        Name name;

        // API Overview
        Description description;
        
        // Resource Groups
        Collection<ResourceGroup>::type resourceGroups;
    };
}

#endif