#pragma once
#include <iostream>
#include <vulkan/vulkan.h>

#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <SDL2/SDL_vulkan.h>
#include <vector>

struct SwapChainSupportDetails
{
    VkSurfaceCapabilitiesKHR capabilities;
    std::vector<VkSurfaceFormatKHR> formats;
    std::vector<VkPresentModeKHR> presentModes;
};

class App
{
public:
    void run();

private:
    SDL_Window *window = nullptr;
    VkSurfaceKHR surface;

    bool quit = false;

    VkExtent2D extent = {1280, 720};

    VkInstance instance;
    VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
    VkDevice device = VK_NULL_HANDLE;

    unsigned int graphicsQueueIndex = -1;
    VkQueue graphicsQueue = nullptr;
    unsigned int presentQueueIndex = -1;
    VkQueue presentQueue = nullptr;

    VkDebugUtilsMessengerEXT debugMessenger = VK_NULL_HANDLE;

    VkSurfaceFormatKHR surfaceFormat;
    VkPresentModeKHR presentMode;

    VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR> &availableFormats);
    VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR> &availablePresentModes);

    SwapChainSupportDetails currentSwapChainSupport;
    SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);

    VkSwapchainKHR swapChain;
    std::vector<VkImageView> swapChainImageViews;
    std::vector<VkImage> swapChainImages;

    VkShaderModule vertShaderModule;
    VkShaderModule fragShaderModule;

    VkPipelineLayout pipelineLayout;
    VkPipeline graphicsPipeline;

    VkRenderPass renderPass;

    std::vector<VkFramebuffer> swapChainFramebuffers;

    VkCommandPool commandPool;
    VkCommandBuffer commandBuffer;

    VkSemaphore imageAvailableSemaphore;
    VkSemaphore renderFinishedSemaphore;
    VkFence inFlightFence;

    void createInstance(SDL_Window *window);
    void init();
    void drawFrame();
    void mainLoop();
    void cleanup();
    void getPhysicalDevice();
    void getQueueFamilyIndices();
    void createLogicalDevice();
    bool isDeviceSuitable(VkPhysicalDevice device);
    void createSwapChain();
    void createImageViews();
    void createGraphicsPipeline();
    void createRenderPass();
    void createFrameBuffers();
    void createCommandPool();
    void createCommandBuffer();
    void recordCommandBuffer(VkCommandBuffer commandBuffer, unsigned int imageIndex);
    void createSyncObjects();
};