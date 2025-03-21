#pragma once
#include "Prerequisites.h"

// Declaraciones
class Window;
class Device;
class DeviceContext;

class
UserInterface {
public:
  UserInterface() = default;
  ~UserInterface() = default;

  /**
   * @brief Configura e inicializa la interfaz de usuario.
   */
  void
  init(void* window,
       ID3D11Device* device,
       ID3D11DeviceContext* deviceContext);

  /**
   * @brief Actualiza los elementos de la interfaz de usuario en cada ciclo de ejecuci�n.
   */
  void
  update();

  /**
   * @brief Llama a las funciones de renderizado de ImGui
   */
  void
  render();

  /**
   * @brief Libera los recursos gr�ficos asignados a la interfaz de usuario.
   */
  void
  destroy();

  /**
   * @brief Aplica un estilo visual similar al de CS:GO en la interfaz de usuario.
   */
  void
    SetCSGOStyle();

  /**
   * @brief Organizar los elementos posici�n, rotaci�n y escala del modelo 3D.
   */
  void
    Position();

private:
};