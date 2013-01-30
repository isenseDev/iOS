// -*- mode:c++; tab-width:2; indent-tabs-mode:nil; c-basic-offset:2 -*-
/*
 *  GenericGF.h
 *  zxing
 *
 *  Created by Lukas Stabe on 13/02/2012.
 *  Copyright 2012 ZXing authors All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef GENERICGF_H
#define GENERICGF_H

#include <vector>
#include <zxing/common/Counted.h>

namespace zxing {
  class GenericGFPoly;
  
  class GenericGF : public Counted {
    
  private:
    std::vector<int> expTable_;
    std::vector<int> logTable_;
    Ref<GenericGFPoly> zero_;
    Ref<GenericGFPoly> one_;
    int size_;
    int primitive_;
    bool initialized_;
    
    void initialize();
    void checkInit();
    
  public:
    static Ref<GenericGF> AZTEC_DATA_12;
    static Ref<GenericGF> AZTEC_DATA_10;
    static Ref<GenericGF> AZTEC_DATA_8;
    static Ref<GenericGF> AZTEC_DATA_6;
    static Ref<GenericGF> AZTEC_PARAM;
    static Ref<GenericGF> QR_CODE_FIELD_256;
    static Ref<GenericGF> DATA_MATRIX_FIELD_256;
    
    GenericGF(int primitive, int size);
    
    Ref<GenericGFPoly> getZero();
    Ref<GenericGFPoly> getOne();
    int getSize();
    Ref<GenericGFPoly> buildMonomial(int degree, int coefficient);
    
    static int addOrSubtract(int a, int b);
    int exp(int a);
    int log(int a);
    int inverse(int a);
    int multiply(int a, int b);
      
    bool operator==(GenericGF other) {
      return (other.getSize() == this->size_ &&
              other.primitive_ == this->primitive_);
    }
    
    //#warning todo: add print method
    
  };
}

#endif //GENERICGF_H

