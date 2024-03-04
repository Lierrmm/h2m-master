#pragma once

#include "utils/info_string.hpp"

enum class game_type
{
	unknown = 0,
	h2
};

inline const std::string& resolve_game_type_name(const game_type game)
{
	static const std::unordered_map<game_type, std::string> names =
	{
		{game_type::unknown, "Unknown"},
		{game_type::h2, "H2"}
	};

	return names.at(game);
}

inline game_type resolve_game_type(const std::string& game_name)
{
	if (game_name == "H2")
	{
		return game_type::h2;
	}

	return game_type::unknown;
}

struct game_server
{
	enum class state
	{
		can_ping = 0,
		needs_ping,
		pinged,
		dead,
	};

	state state{state::can_ping};
	bool registered{false};

	game_type game{game_type::unknown};
	int protocol{};
	uint32_t clients{};
	std::string name{};
	std::string challenge{};
	utils::info_string info_string{};
	std::chrono::high_resolution_clock::time_point heartbeat{};
};
