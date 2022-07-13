/*
 * Copyright 2002 by Mortice Kern Systems Inc. All rights reserved.
 */

/*
 * This script should be set on post event for addmember and dropmember. This
 * script will write a log file to the log directory named addDropMemberLogging.log.
 * In this file it will write the project name, the date/time and action that occured.
 */

/* Lookup all necessary beans */
var environmentBean = bsf.lookupBean("siEnvironmentBean");
var projectBean = bsf.lookupBean("siProjectBean");
var userBean = bsf.lookupBean("siUserBean");
var addEeventArgsBean = bsf.lookupBean("siAddMemberArgumentsBean");
var dropEeventArgsBean = bsf.lookupBean("siDropMemberArgumentsBean");

var out = new java.io.PrintWriter(new java.io.FileWriter("../log/addDropMemberLogging.log",true));
out.println("Time: " + java.util.Date());
out.println("Project: " + projectBean.getDisplayName());
out.println("User: " + userBean.getUsername());
out.println("Event: " + environmentBean.getEventName());
if( addEeventArgsBean != null ) {
	out.println("Member: " + addEeventArgsBean.getMember());
} else {
	out.println("Member: " + dropEeventArgsBean.getMemberName());
}
out.close();
