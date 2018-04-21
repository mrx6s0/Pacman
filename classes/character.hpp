
#ifndef CHARACTER_H

#define CHARACTER_H

#include <allegro5/allegro.h>

#include <allegro5/allegro_native_dialog.h>

class Character
{
protected:
  int direction, character_col, character_line, size;

  ALLEGRO_BITMAP *img;

public:
  void draw(void);

  void setDirection(const int);

  int getDirection(void);

  void setCharacterCol(const int);

  int getCharacterCol(void);

  void setCharacterLine(const int);

  int getCharacterLine(void);

  void setSize(const int);

  int getSize(void);

  void set(const int, const int, const int);

  bool moveLeft(char map[][17]);

  bool moveRight(char map[][17]);

  bool moveUp(char map[][17]);

  bool moveDown(char map[][17]);

  bool move(const int, char map[][17]);

  // ~Character(void);
};

#endif