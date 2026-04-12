#encoding=utf-8
import sys
data1, data2 = [], []


while True:
    x = map(int, raw_input().split(","))
    if sum(x) == 0:
        break
    data1.append([x[1], x[0]])

i = 1
data1 = sorted(data1)[::-1]
data1[0].insert(2,1)
ma = data1[0][0]

while True:
    if ma == data1[i][0]:
        data1[i].insert(2, (data1[i - 1][2]))
    elif ma > data1[i][0]:
        data1[i].insert(2,((data1[i - 1][2]) + 1))
        ma = data1[i][0]
    i += 1
    if i >= len(data1):
        break


for i in sys.stdin:
    for j in xrange(len(data1)):
        if int(i) == data1[j][1]:
            print data1[j][2]
            break