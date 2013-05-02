//
//  RegexMatch.h
//  snowcrash
//
//  Created by Zdenek Nemec on 5/2/13.
//  Copyright (c) 2013 Apiary.io. All rights reserved.
//

#ifndef SNOWCRASH_REGEXMATCH_H
#define SNOWCRASH_REGEXMATCH_H

#include <string>

namespace snowcrash {

    // Perform snowcrash-specific regex evaluation
    // returns true if target string matches given expression, false otherwise
    bool RegexMatch(const std::string& target, const std::string& expression);
}

#endif