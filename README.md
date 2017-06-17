# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---

## Summary
####Describe the effect each of the P, I, D components had in your implementation.
* `P`: affected how much the car oscillated around the center of the lane, when I initially started started tuning I set the P parameter to 1 and this was way too high as the car eventually went of the road after oscillating to much. 
* `D`: damped the oscillations caused by P, and improved the speed at which the car settled on a driving path.
* `I`: did not noticiably change anything, but it did lower the average CTE so I added it.

Increasing P and D too much caused the calculated steering to max out the cars steering and it would just max turn back and forth and drive really slow. 

####Describe how the final hyperparameters were chosen.
* I chose my hyperparameters by manually tuning them. I started with `P=0.5`, `I=0.0`, `D=0.5`. Then I adjusted them
based on the average CTE after completing a lap. If I changed a parameter and the avg CTE decreased then I kept
the adjustment. Initially I didn't think the `I` coefficient would be needed in the simulator, but I noticed the average CTE never reached below a certain number implying there was some steering bias. So I added `I`, and although it did decrease the average CTE it still did not 
bring below 0.27. 
My final parameters were:
`P=0.2`
`I=0.001`
`D=2.2`

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets 
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 

