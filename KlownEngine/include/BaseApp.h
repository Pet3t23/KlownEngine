#pragma once
#include "Prerequisites.h"
#include "Window.h"
#include "Device.h"
#include "DeviceContext.h"
#include "Swapchain.h"
#include "Texture.h"
#include "RenderTargetView.h"
#include "DepthStencilView.h"
#include "Viewport.h"
#include "ShaderProgram.h"
#include "MeshComponent.h"
#include "Buffer.h"
#include "SamplerState.h"
#include "UserInterface.h"

class
  BaseApp {
public:
  /**
   * @brief Constructores por fefecto
   */
  BaseApp() = default;
  ~BaseApp() = default;

  /**
   * @brief Inicia la ventana con todos los recursos
   */
  HRESULT
  init();

  /**
   * @brief Actualiza la lógica de la ventana en cada frame
   */
  void
  update();

  /**
   * @brief Renderiza la ventana
   */
  void
  render();

  /**
   * @brief Libera los recursos
   */
  void
  destroy();

  /**
   * @brief Reajusta el tamaño de la pantalla
   */
  HRESULT
  ResizeWindow(HWND hWnd, LPARAM lParam);

  /**
  * @brief Maneja los inputs actions para el movimiento del cubo y la cámara
  */
  void
  inputActionMap(float deltaTime);

  /**
  * @brief  Actualiza la matriz de la cámara
  */
  void
  UpdateCamera();

  /**
  * @brief Rota la cámara dependiendo de la última posición del mouse.
  */
  void
  RotateCamera(int mouseX, int mouseY);

  /**
   * @brief Corre la aplicación
   */
  int
  run(HINSTANCE hInstance,
      HINSTANCE hPrevInstance,
      LPWSTR lpCmdLine,
      int nCmdShow,
      WNDPROC wndproc);

public:
  Window                              m_window;
  Device                              m_device;
  DeviceContext                       m_deviceContext;
  SwapChain                           m_swapchain;
  Texture                             m_backBuffer;
  Texture                             m_depthStencil;
  RenderTargetView                    m_renderTargetView;
  DepthStencilView                    m_depthStencilView;
  Viewport                            m_viewport;
  ShaderProgram                       m_shaderProgram;
  Buffer                              m_vertexBuffer;
  Buffer                              m_indexBuffer;
  Buffer                              m_neverChanges;
  Buffer                              m_changeOnResize;
  Buffer                              m_changesEveryFrame;
  CBChangesEveryFrame cb;
  CBNeverChanges cbNeverChanges;
  CBChangeOnResize cbChangesOnResize;
  Texture                             m_textureRV;
  SamplerState                        m_samplerState;
  UserInterface                       m_ui;

  XMMATRIX                            m_modelMatrix;
  XMMATRIX                            m_View;
  XMMATRIX                            m_Projection;
  MeshComponent MC;

  Camera m_camera;
  XMFLOAT3 position;
  XMFLOAT3 rotation;
  XMFLOAT3 scale;

  bool keys[256] = { false };
  int lastX;
  int lastY;
  float sensitivity = 0.01f;
  bool mouseLeftDown = false;
};