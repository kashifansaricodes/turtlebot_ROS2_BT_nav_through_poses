#pragma once
#include "rclcpp/rclcpp.hpp"
#include "behaviortree_cpp_v3/bt_factory.h"
#include "navigation_behaviors.hpp"
#include "ament_index_cpp/get_package_share_directory.hpp"

#include <tf2/LinearMath/Quaternion.h>

#include <behaviortree_cpp_v3/action_node.h>

class StopRobot : public BT::SyncActionNode
{
public:
    StopRobot(const std::string& name, const BT::NodeConfiguration& config)
        : BT::SyncActionNode(name, config) {}

    static BT::PortsList providedPorts() {
        return { };
    }

    BT::NodeStatus tick() override {
        // Implement the logic to stop the robot or finalize the task.
        RCLCPP_INFO(rclcpp::get_logger("StopRobot"), "Stopping robot");
        return BT::NodeStatus::SUCCESS;
    }
};
