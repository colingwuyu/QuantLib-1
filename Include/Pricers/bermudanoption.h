     
/*
 * Copyright (C) 2001
 * Ferdinando Ametrano, Luigi Ballabio, Adolfo Benin, Marco Marchioro
 * 
 * This file is part of QuantLib.
 * QuantLib is a C++ open source library for financial quantitative
 * analysts and developers --- http://quantlib.sourceforge.net/
 *
 * QuantLib is free software and you are allowed to use, copy, modify, merge,
 * publish, distribute, and/or sell copies of it under the conditions stated 
 * in the QuantLib License.
 *
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the license for more details.
 *
 * You should have received a copy of the license along with this file;
 * if not, contact ferdinando@ametrano.net
 *
 * QuantLib license is also available at 
 *      http://quantlib.sourceforge.net/LICENSE.TXT
*/

/*! \file bermudanoption.h
    \brief class for finite-difference evaluation of bermudan option 
    
    $Source$
    $Log$
    Revision 1.1  2001/03/21 09:51:47  marmar
    simple BermudanOption pricer added

*/

#ifndef shaft_bermudan_option_pricer_h
#define shaft_bermudan_option_pricer_h

#include "qldefines.h"
#include "multiperiodoption.h"

namespace QuantLib {

    namespace Pricers {

        class BermudanOption : public MultiPeriodOption {
          public:
            // constructor
            BermudanOption(Type type, double underlying, 
                double strike, Rate dividendYield, Rate riskFreeRate, 
                Time residualTime, double volatility, 
                const std::vector<Time>& dates = std::vector<Time>(), 
                int timeSteps = 100, int gridPoints = 100);
            Handle<BSMOption> clone() const { 
                return Handle<BSMOption>(new BermudanOption(*this));
            }
          protected:
            void initializeStepCondition() const;
            void executeIntermediateStep(int) const;
        };

    }
}

#endif
