#!/usr/bin/python3
from gpiozero import LED, Button
from signal import pause
from subprocess import check_call

command_on = ["sudo", "systemctl", "restart", "kameres"]
command_off = ["sudo", "systemctl", "stop", "kameres"]


led = LED(17)
button = Button(2)

def turn_on():
    print("Turn on!")
    led.on()
    #result = subprocess.run(command_on, capture_output=True, text=True)
    check_call(command_on)

def turn_off():
    print("Turn off!")
    led.off()
    #result = subprocess.run(command_off, capture_output=True, text=True)
    check_call(command_off)

button.when_pressed = turn_on
button.when_released = turn_off

pause()
