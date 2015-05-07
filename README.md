# queue_manager
Server Side ROS Queue Node

#Notes From Peter
Topics:

 - rms_queue - publishes for each user: user id, time left in queue (valid for non 1st user only), and time left in study (valid for 1st user only)

Services:

 - update_queue - called by the web interface when someone: loads the webpage, reloads the webpage, exist the browser, or navigates to another website

Other Notes:
I have observed the following bugs in the queue, although couldn't find steps to reproduce them

 - study time can go negative when all users leave the queue. This has never caused any inappropriate behavior though, since it only happens when everyone leaves
 - study time described in the Ros_Queue object may not be respected, and will default to 10 minute trials. It should work but I has at times not worked. At least you know it's possible.
