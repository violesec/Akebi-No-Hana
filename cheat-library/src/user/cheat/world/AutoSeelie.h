#pragma once
#include <cheat-base/cheat/Feature.h>
#include <cheat-base/config/config.h>

#include <cheat/game/Entity.h>
#include <cheat/game/filters.h>
#include <il2cpp-appdata.h>

namespace cheat::feature
{

	class AutoSeelie : public Feature
	{
	public:
		config::Field<config::Toggle<Hotkey>> f_Enabled;

		static AutoSeelie& GetInstance();

		const FeatureGUIInfo& GetGUIInfo() const override;
		void DrawMain() override;

		virtual bool NeedStatusDraw() const override;
		void DrawStatus() override;

		void OnGameUpdate();
	private:

		std::vector<game::IEntityFilter*> m_Filters;
		AutoSeelie();
		int nextTime{};
		bool IsEntityForVac(cheat::game::Entity* entity);
	};
}
