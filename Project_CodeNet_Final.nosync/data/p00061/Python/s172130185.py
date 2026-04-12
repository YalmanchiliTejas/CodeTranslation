import sys
import fileinput
import math

ips = []
for line in fileinput.input():
    ips.append(line)

data = []
i = 0
while True:
    ip = [ int(i) for i in ips[i].strip().split(',')]
    if ip == [0,0] : break;
    else: data.append(ip)
    i+=1

data = sorted(data,key=lambda x:-x[1])
counter = 0
score = -1

m = {}
for k, s in data:
    if s != score:
        counter+=1
        score = s
    m[k] = counter

for a in range(i+1, len(ips)):
    ip = int(ips[a].strip())
    print(m[ip])