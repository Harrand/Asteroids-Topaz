#ifndef TOPAZASTEROIDS_PLAYER_HPP
#define TOPAZASTEROIDS_PLAYER_HPP
#include "graphics/sprite.hpp"
#include "physics/physics_object.hpp"
#include "bullet.hpp"

class EntityManager;

class Player : public Sprite, public PhysicsObject
{
public:
    Player(Vector2I position, float rotation, Vector2F scale, const Texture* player_texture);
    Vector2F forward() const;
    virtual void update(float delta) override;
    virtual std::optional<AABB> get_boundary() const;
    virtual void on_collision([[maybe_unused]] PhysicsObject& other){}
    Bullet& shoot(EntityManager& entity_manager);
    static void play_shoot_sound();
private:
    const Texture* texture;
};


#endif //TOPAZASTEROIDS_PLAYER_HPP
