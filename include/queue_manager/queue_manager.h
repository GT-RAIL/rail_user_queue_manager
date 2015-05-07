//
// Created by pdmitrano on 4/1/15.
//

#ifndef QUEUE_MANAGER_H_
#define QUEUE_MANAGER_H_

#include <ros/ros.h>
#include <queue_manager/Queue.h>
#include <queue_manager/UserStatus.h>
#include <queue_manager/UpdateQueue.h>
#include <deque>

class QueueManager
{
public:
  /*!brief The frequency of the loop in (1/seconds). This is how often we publish the queue */
  static const int LOOP_RATE = 1;
  /*! default length of trial is 600 seconds. This will always be overwritten if the enqueue */
  static const int DEFAULT_TRIAL = 600;

  /*!
   * \brief This starts the server, waits for param server and create clickable parking spots
   */
  QueueManager();

private:
  /*! the queue to hold the user_ids and wait times in order. */
  std::deque<std::pair<int, int> > queue_;
  /*! keeps track of the time left for the active user */
  int countdown_;
  /*! run countdown if there is someone in the queue */
  bool run_countdown_;
  /*! Private node handle. */
  ros::NodeHandle private_node_;

  /*!
   * \brief Add or remove a user to the deque
   */
  bool onUpdateQueue(queue_manager::UpdateQueue::Request &req, queue_manager::UpdateQueue::Response &res);

};

#endif
