#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include "Date.h"
#include "Parser.h"
#include <set>

class Configuration: commonItems::parser
{
  public:
	Configuration();
	explicit Configuration(std::istream& theStream);

	enum class STARTDATE
	{
		EU = 1,
		CK = 2
	};
	enum class SPLITVASSALS
	{
		YES = 1,
		NO = 2
	};
	enum class DEJURE
	{
		ENABLED = 1,
		DISABLED = 2
	};
	enum class DEVELOPMENT
	{
		IMPORT = 1,
		VANILLA = 2
	};
	enum class SUNSET
	{
		DEFAULT = 1,
		DISABLED = 2,
		ACTIVE = 3
	};
	enum class I_AM_HRE
	{
		HRE = 1,
		BYZANTIUM = 2,
		ROME = 3,
		CUSTOM = 4,
		NONE = 5
	};
	enum class SHATTER_EMPIRES
	{
		NONE = 1,
		ALL = 2,
		CUSTOM = 3
	};
	enum class SHATTER_LEVEL
	{
		DUTCHY = 1,
		KINGDOM = 2
	};
	enum class SHATTER_HRE_LEVEL
	{
		DUTCHY = 1,
		KINGDOM = 2
	};
	enum class SIBERIA
	{
		CLEAR_SIBERIA = 1,
		LEAVE_SIBERIA = 2
	};
	enum class INSTITUTIONS
	{
		HISTORIC = 1,
		DYNAMIC = 2
	};

	[[nodiscard]] const auto& getSaveGamePath() const { return SaveGamePath; }
	[[nodiscard]] const auto& getCK2Path() const { return CK2Path; }
	[[nodiscard]] const auto& getCK2ModsPath() const { return CK2ModsPath; }
	[[nodiscard]] const auto& getEU4Path() const { return EU4Path; }
	[[nodiscard]] const auto& getOutputName() const { return outputName; }
	[[nodiscard]] const auto& getHRE() const { return iAmHre; }
	[[nodiscard]] const auto& getShatterEmpires() const { return shatterEmpires; }
	[[nodiscard]] const auto& getShatterLevel() const { return shatterLevel; }
	[[nodiscard]] const auto& getDejure() const { return dejure; }
	[[nodiscard]] const auto& getShatterHRELevel() const { return shatterHRELevel; }
	[[nodiscard]] const auto& getSiberia() const { return siberia; }
	[[nodiscard]] const auto& getSunset() const { return sunset; }
	[[nodiscard]] const auto& getDynamicInstitutions() const { return dynamicInstitutions; }
	[[nodiscard]] const auto& getDevelopment() const { return development; }
	[[nodiscard]] const auto& getModFileNames() const { return modFileNames; }
	[[nodiscard]] const auto& getSplitVassals() const { return splitVassals; }
	[[nodiscard]] const auto& getStartDateOption() const { return startDate; }

  private:
	void registerKeys();
	void setOutputName();
	void verifyCK2Path() const;
	void verifyEU4Path() const;

	std::string SaveGamePath;
	std::string CK2Path;
	std::string CK2ModsPath;
	std::string EU4Path;
	std::string outputName;

	STARTDATE startDate = STARTDATE::EU;
	I_AM_HRE iAmHre = I_AM_HRE::HRE;
	SHATTER_EMPIRES shatterEmpires = SHATTER_EMPIRES::NONE;
	SHATTER_HRE_LEVEL shatterHRELevel = SHATTER_HRE_LEVEL::DUTCHY;
	SHATTER_LEVEL shatterLevel = SHATTER_LEVEL::DUTCHY;
	SIBERIA siberia = SIBERIA::CLEAR_SIBERIA;
	SUNSET sunset = SUNSET::DEFAULT;
	INSTITUTIONS dynamicInstitutions = INSTITUTIONS::HISTORIC;
	DEVELOPMENT development = DEVELOPMENT::IMPORT;
	DEJURE dejure = DEJURE::ENABLED;
	SPLITVASSALS splitVassals = SPLITVASSALS::YES;

	std::set<std::string> modFileNames;
};

#endif // CONFIGURATION_H
