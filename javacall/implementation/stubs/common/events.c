/*
 * Copyright  1990-2008 Sun Microsystems, Inc. All Rights Reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License version
 * 2 only, as published by the Free Software Foundation.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License version 2 for more details (a copy is
 * included at /legal/license.txt).
 * 
 * You should have received a copy of the GNU General Public License
 * version 2 along with this work; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 * 02110-1301 USA
 * 
 * Please contact Sun Microsystems, Inc., 4150 Network Circle, Santa
 * Clara, CA 95054 or visit www.sun.com if you need additional
 * information or have any questions.
 */

#include "javacall_events.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Mandatory event functions:
 * - javacall_events_init()
 * - javacall_events_finalize()
 *
 * Functions specific for CLDC-based implementations:
 * - javacall_event_receive()
 * - javacall_event_send()
 *
 * Functions specific for CDC-based implementations:
 * - javacall_event_receive_cvm()
 * - javacall_event_send_cvm()
 */
    
/**
 * CLDC-specific function.
 * Waits for an incoming event message and copies it to user supplied
 * data buffer
 * @param waitForever indicate if the function should block forever
 * @param timeTowaitInMillisec max number of seconds to wait
 *              if waitForever is false
 * @param binaryBuffer user-supplied buffer to copy event to
 * @param binaryBufferMaxLen maximum buffer size that an event can be 
 *              copied to.
 *              If an event exceeds the binaryBufferMaxLen, then the first
 *              binaryBufferMaxLen bytes of the events will be copied
 *              to user-supplied binaryBuffer, and JAVACALL_OUT_OF_MEMORY will 
 *              be returned
 * @param outEventLen user-supplied pointer to variable that will hold actual 
 *              event size received
 *              Platform is responsible to set this value on success to the 
 *              size of the event received, or 0 on failure.
 *              If outEventLen is NULL, the event size is not returned.
 * @return <tt>JAVACALL_OK</tt> if an event successfully received, 
 *         <tt>JAVACALL_FAIL</tt> or if failed or no messages are avaialable
 *         <tt>JAVACALL_OUT_OF_MEMORY</tt> If an event's size exceeds the 
 *         binaryBufferMaxLen 
 */
javacall_result javacall_event_receive(
                            long                     timeTowaitInMillisec,
                            /*OUT*/ unsigned char*  binaryBuffer,
                            /*IN*/  int             binaryBufferMaxLen,
                            /*OUT*/ int*            outEventLen){
    return JAVACALL_NOT_IMPLEMENTED;
}
/**
 * CLDC-specific function.
 * copies a user supplied event message to a queue of messages
 *
 * @param binaryBuffer a pointer to binary event buffer to send
 *        The platform should make a private copy of this buffer as
 *        access to it is not allowed after the function call.
 * @param binaryBufferLen size of binary event buffer to send
 * @return <tt>JAVACALL_OK</tt> if an event successfully sent, 
 *         <tt>JAVACALL_FAIL</tt> or negative value if failed
 */
javacall_result javacall_event_send(unsigned char* binaryBuffer,
                                    int binaryBufferLen){
    return JAVACALL_NOT_IMPLEMENTED;
}    

/**
 * CDC-specific function.
 * Waits for an incoming event in the queue with the given ID and copies it to
 * a user supplied data buffer.
 *
 * @param queueId identifier of an event queue, typically a JSR number.
 * @param binaryBuffer user-supplied buffer to copy event to.
 * @param binaryBufferMaxLen maximum buffer size that an event can be
 *              copied to.
 * @param outEventLen user-supplied pointer to variable that will hold actual 
 *              event size received, or desired buffer size if
 *              binaryBufferMaxLen is insufficient.
 *              If outEventLen is NULL, the event size is not returned.
 * @return <tt>JAVACALL_OK</tt> if an event successfully received,
 *         <tt>JAVACALL_OUT_OF_MEMORY</tt> if event size exceeds
 *         binaryBufferMaxLen,
 *         <tt>JAVACALL_FAIL</tt> on any other error.
 */
javacall_result javacall_event_receive_cvm(int queueId,
    /*OUT*/ unsigned char *binaryBuffer, int binaryBufferMaxLen,
    /*OUT*/ int *outEventLen) {
    return JAVACALL_NOT_IMPLEMENTED;
}

/**
 * CDC-specific function.
 * Copies a user supplied event message to a queue of messages and wakes up the
 * thread that is waiting for events on the queue with the given id.
 *
 * @param queueId identifier of an event queue, typically a JSR number.
 * @param binaryBuffer a pointer to binary event buffer to send. The first int
 *        is the event id.
 * @param binaryBufferLen size of binary event buffer to send.
 * @return <tt>JAVACALL_OK</tt> if an event has been successfully sent,
 *         <tt>JAVACALL_FAIL</tt> otherwise.
 */
javacall_result javacall_event_send_cvm(int queueId,
    unsigned char* binaryBuffer, int binaryBufferLen) {
    return JAVACALL_NOT_IMPLEMENTED;
}

/**
 * The function is called during Java VM startup, allowing the
 * platform to perform specific initializations. It is called in the same
 * process as javacall_event_receive() and javacall_events_finalize().
 *
 * @return <tt>JAVACALL_OK</tt> on success,
 *         <tt>JAVACALL_FAIL</tt> otherwise
 */
javacall_result javacall_events_init(void) {
    return JAVACALL_NOT_IMPLEMENTED;
}

/**
 * The function is called during Java VM shutdown, allowing the platform to
 * perform specific events-related shutdown operations. It is called in the same
 * process as javacall_events_init() and javacall_event_receive().
 *
 * @return <tt>JAVACALL_OK</tt> on success,
 *         <tt>JAVACALL_FAIL</tt> otherwise
 */
javacall_result javacall_events_finalize(void) {
    return JAVACALL_NOT_IMPLEMENTED;
}

#ifdef __cplusplus
}
#endif

