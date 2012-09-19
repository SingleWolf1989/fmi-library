/*
    Copyright (C) 2012 Modelon AB

    This program is free software: you can redistribute it and/or modify
    it under the terms of the BSD style license.

     This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    FMILIB_License.txt file for more details.

    You should have received a copy of the FMILIB_License.txt file
    along with this program. If not, contact Modelon AB <http://www.modelon.com>.
*/

#ifndef FMI2_ENUMS_H_
#define FMI2_ENUMS_H_

#include <fmilib_config.h>

#ifdef __cplusplus
extern "C" {
#endif

/** \file fmi2_enums.h 
	\brief Definions the enum types used with FMI 1.0 libs
*/

/**	\addtogroup fmi2_utils
	@{
	\addtogroup fmi2_enums
	@}
*/
/** \addtogroup fmi2_enums Enum types used with FMI 1.0 libs
	@{
*/
/** \brief Naming convention for the variables in XML file*/
typedef enum fmi2_variable_naming_convension_enu_t
{ 
        fmi2_naming_enu_flat,
        fmi2_naming_enu_structured,
        fmi2_naming_enu_unknown
} fmi2_variable_naming_convension_enu_t;

/** \brief Convert a #fmi2_variable_naming_convension_enu_t constant into string */
FMILIB_EXPORT const char* fmi2_naming_convention_to_string(fmi2_variable_naming_convension_enu_t convention);

/**  \brief FMU 2.0 kinds */
typedef enum fmi2_fmu_kind_enu_t
{
		fmi2_fmu_kind_unknown = 0,
        fmi2_fmu_kind_me = 1,
        fmi2_fmu_kind_cs = 2,
        fmi2_fmu_kind_me_and_cs = 3
} fmi2_fmu_kind_enu_t;

/** \brief Convert a #fmi2_fmu_kind_enu_t constant into string  */
FMILIB_EXPORT const char* fmi2_fmu_kind_to_string(fmi2_fmu_kind_enu_t kind);

/**  \brief Variability property for variables */
typedef enum fmi2_variability_enu_t {
        fmi2_variability_enu_constant,
        fmi2_variability_enu_fixed,
        fmi2_variability_enu_tunable,
        fmi2_variability_enu_discrete,
        fmi2_variability_enu_continuous,
		fmi2_variability_enu_unknown
} fmi2_variability_enu_t;

/** \brief Convert a #fmi2_variability_enu_t constant into string  */
FMILIB_EXPORT const char* fmi2_variability_to_string(fmi2_variability_enu_t v);

/**  \brief Causality property for variables */
typedef enum fmi2_causality_enu_t {
        fmi2_causality_enu_parameter,
        fmi2_causality_enu_input,
        fmi2_causality_enu_output,
        fmi2_causality_enu_local,
        fmi2_causality_enu_unknown
} fmi2_causality_enu_t;

/** \brief Convert a #fmi2_causality_enu_t constant into string  */
FMILIB_EXPORT const char* fmi2_causality_to_string(fmi2_causality_enu_t c);

/**  \brief Initial property for variables */
typedef enum fmi2_initial_enu_t {
        fmi2_initial_enu_exact,
        fmi2_initial_enu_approx,
        fmi2_initial_enu_calculated,
        fmi2_initial_enu_unknown
} fmi2_initial_enu_t;

/** \brief Convert a #fmi2_initial_enu_t constant into string  */
FMILIB_EXPORT const char* fmi2_initial_to_string(fmi2_initial_enu_t c);

/** \brief Alias property for variables */
typedef enum fmi2_variable_alias_kind_enu_t {
    fmi2_variable_is_not_alias = 0,
    fmi2_variable_is_alias = 1
} fmi2_variable_alias_kind_enu_t;

/** \brief Base types used in type definitions */
typedef enum fmi2_base_type_enu_t
{
	fmi2_base_type_real,
	fmi2_base_type_int,
	fmi2_base_type_bool,
	fmi2_base_type_str,
	fmi2_base_type_enum
} fmi2_base_type_enu_t;

/**  \brief Convert base type constant to string 
	\param bt Base type identifier.
	\return Corresponding base type name.
	*/
FMILIB_EXPORT const char* fmi2_base_type_to_string(fmi2_base_type_enu_t bt);

/** \brief List of capability flags for ModelExchange */
#define FMI2_ME_CAPABILITIES(H) \
	H(needsExecutionTool) \
	H(completedIntegratorStepNotNeeded) \
	H(canBeInstantiatedOnlyOncePerProcess) \
	H(canNotUseMemoryManagementFunctions) \
	H(canGetAndSetFMUstate) \
	H(canSerializeFMUstate) \
	H(providesDirectionalDerivatives)

/** \brief List of capability flags for CoSimulation */
#define FMI2_CS_CAPABILITIES(H) \
	H(needsExecutionTool) \
	H(canHandleVariableCommunicationStepSize) \
	H(canHandleEvents) \
	H(canInterpolateInputs) \
	H(maxOutputDerivativeOrder) \
	H(canRunAsynchronuously) \
	H(canSignalEvents) \
	H(canBeInstantiatedOnlyOncePerProcess) \
	H(canNotUseMemoryManagementFunctions) \
	H(canGetAndSetFMUstate) \
	H(canSerializeFMUstate)

/** \brief Capability flags for ModelExchange and CoSimulation */
typedef enum fmi2_capabilities_enu_t {
#define FMI2_EXPAND_ME_CAPABILITIES_ENU(c) fmi2_me_ ## c,
#define FMI2_EXPAND_CS_CAPABILITIES_ENU(c) fmi2_cs_ ## c,
	FMI2_ME_CAPABILITIES(FMI2_EXPAND_ME_CAPABILITIES_ENU)
	FMI2_CS_CAPABILITIES(FMI2_EXPAND_CS_CAPABILITIES_ENU)
	fmi2_capabilities_Num
} fmi2_capabilities_enu_t;


/** \brief Convert capability flag to a string 
	\param id Capability flag ID.
	\return Name of the flag or Unknown if the id is out of range.
*/
FMILIB_EXPORT const char * fmi2_capability_to_string(fmi2_capabilities_enu_t id);

/**	
 @}
*/
#ifdef __cplusplus
}
#endif

#endif /* End of header file FMI2_ENUMS_H_ */