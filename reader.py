#!/usr/bin/env python -u
import serial
import numpy as np
import matplotlib.pyplot as plt

ser = serial.Serial('/dev/ttyACM0',115200)
  
ls1=[]
counter=0
plt.ion()
while(True):
   if(ser.read(1)=='-'):
      try:
         ls1.append(3.3/65000.0*int(ser.read(4),16))
         print ls1[-1]
      except:
         continue
   counter+=1
   plt.clf()
   a=len(ls1)
   if(a%5==0):
      plt.title("ADC Voltage vs. Time")
      plt.xlabel("t")
      plt.ylabel("V")
      plt.scatter(np.arange(a),ls1)
      plt.pause(0.00001)
ser.close()
quit()
