# Navigation 2 demo in ROS2 using TurtleBot3 (Humble)

## Video deomnstration: (https://drive.google.com/file/d/1tbknKB4ixVPEkprCjwKfoI04seEsBDbU/view?usp=sharing)


0. Install Dependencies
```
sudo apt-get install libzmq3-dev libboost-dev

pip3 install transforms3d

```


2. Import TurtleBot3 packages with vcs <<< !!!
```
vcs import . < turtlebot3.repos
```
2. Build all packages from workspace directory (`turtlebot3_ws`)
```
colcon build --symlink-install

Ignore sterr output (that's a warning)
```
3. Source the workspace
```
source ./install/setup.bash
```
5. Export TurtleBot3 model

```
export GAZEBO_MODEL_PATH=$GAZEBO_MODEL_PATH:~/turtlebot3_ws/src/turtlebot3/turtlebot3_simulations/turtlebot3_gazebo/models

export TURTLEBOT3_MODEL=waffle_pi
```

6. Launch turtlebot3 simulation infrastructure

```
ros2 launch tb3_sim turtlebot3_world.launch.py
```

7. Launch nav2 infrastructure (nav2 + amcl initial pose)

```
source ./install/setup.bash
ros2 launch tb3_sim nav2.launch.py
```

8. Launch autonomy behavior for demo

```
source ./install/setup.bash
ros2 launch tb3_autonomy autonomy.launch.py
```

This starts our demonstration where TurtleBot moves between 4 different locations in the world simulation (set in `tb3_sim/config/sim_house_locations.yaml`)
and halults down itself after visiting all the four locations. 


