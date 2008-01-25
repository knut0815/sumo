/****************************************************************************/
/// @file    NIElmar2NodesHandler.h
/// @author  Daniel Krajzewicz
/// @date    Sun, 16 May 2004
/// @version $Id:NIElmar2NodesHandler.h 4701 2007-11-09 14:29:29Z dkrajzew $
///
// Importer of nodes stored in unsplit elmar format
/****************************************************************************/
// SUMO, Simulation of Urban MObility; see http://sumo.sourceforge.net/
// copyright : (C) 2001-2007
//  by DLR (http://www.dlr.de/) and ZAIK (http://www.zaik.uni-koeln.de/AFS)
/****************************************************************************/
//
//   This program is free software; you can redistribute it and/or modify
//   it under the terms of the GNU General Public License as published by
//   the Free Software Foundation; either version 2 of the License, or
//   (at your option) any later version.
//
/****************************************************************************/
#ifndef NIElmar2NodesHandler_h
#define NIElmar2NodesHandler_h


// ===========================================================================
// included modules
// ===========================================================================
#ifdef _MSC_VER
#include <windows_config.h>
#else
#include <config.h>
#endif

#include <string>
#include <utils/importio/LineHandler.h>
#include <utils/common/FileErrorReporter.h>


// ===========================================================================
// class definitions
// ===========================================================================
/**
 * @class NIElmar2NodesHandler
 * @brief Importer of nodes stored in unsplit elmar format
 * Being a LineHandler, this class retrieves each line from a LineReader
 * and parses these information assuming they contain node definitions
 * in Cell-format
 */
class NIElmar2NodesHandler : public LineHandler,
            public FileErrorReporter
{
public:
    /// constructor
    NIElmar2NodesHandler(NBNodeCont &nc, const std::string &file,
                         std::map<std::string, Position2DVector> &geoms) throw();

    /// destructor
    ~NIElmar2NodesHandler() throw();

    /** implementation of the LineHandler-interface called by a LineReader
        interprets the retrieved information and stores it into the global
        NBNodeCont */
    bool report(const std::string &result) throw(ProcessError);

protected:
    SUMOReal myInitX, myInitY;

    NBNodeCont &myNodeCont;

    std::map<std::string, Position2DVector> &myGeoms;

private:
    /// @brief Invalidated copy constructor.
    NIElmar2NodesHandler(const NIElmar2NodesHandler&);

    /// @brief Invalidated assignment operator.
    NIElmar2NodesHandler& operator=(const NIElmar2NodesHandler&);

};


#endif

/****************************************************************************/

