//Custom Player Skins include file

#if defined _CustomPlayerSkins_included
 #endinput
#endif
#define _CustomPlayerSkins_included

#define CPS_NOFLAGS			0
#define CPS_RENDER			(1 << 0) //Does not make the model invisible. (useful for glows)
#define CPS_NOATTACHMENT	(1 << 1) //Does not 'SetParentAttachment' variant.

/**
 * Sets the client's skin from the given path.
 *
 * @param client	Client index
 * @param model		User input for model path
 * @param flags		flags are used to determine what this function does and does not do.
 * @noreturn 
 * @error			Invalid client.
 */
native CPS_SetSkin( client, String:model[], flags );

/**
 * Gets the client's skin entity reference.
 *
 * @param client	Client index
 * @return 			Returns the entity reference of the player's skin, INVALID_ENT_REFERENCE if there is no skin.
 * @error			Invalid client.
 */
native CPS_GetSkin( client );

/**
 * Removes and resets the player and their skin.
 *
 * @param client	Client index
 * @noreturn
 * @error			Invalid client.
 */
native CPS_RemoveSkin( client );

public SharedPlugin:__pl_CustomPlayerSkins =
{
	name = "CustomPlayerSkins",
	file = "CustomPlayerSkins.smx",
#if defined REQUIRE_PLUGIN
	required = 1,
#else
	required = 0,
#endif
};

#if !defined REQUIRE_PLUGIN
public __pl_CustomPlayerSkins_SetNTVOptional()
{
	MarkNativeAsOptional("CPS_SetSkin");
	MarkNativeAsOptional("CPS_GetSkin");
	MarkNativeAsOptional("CPS_RemoveSkin");
}
#endif
