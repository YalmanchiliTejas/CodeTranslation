x =input()
x = int(x)
y = []
for i in range(x):
    z = input()
    z = int(z)
    y.append(z)
y = sorted(y)
sum = 0
left =[]
right = []
center = y[0]
for i in range(int(x/2)):
    left.append(y[2*i+1])
    if x <= 2*i+2: break
    right.append(y[2*i+2])
b = len(left)
prev = y[0]
for i in range(b):
    if not left: break
    a =left.pop()
    sum += abs(prev - a)
    prev = a
    if not left : break
    a= left.pop(0)
    sum += abs(prev - a)
    prev = a
b = len(right)
prev = y[0]
for i in range(b):
    if not right: break
    a =right.pop()
    sum+= abs(prev-a)
    prev = a
    if not right : break
    a= right.pop(0)
    sum+= abs(prev-a)
    prev = a
suma = sum
y.reverse()
sum = 0
left =[]
right = []
center = y[0]
for i in range(int(x/2)):
    left.append(y[2*i+1])
    if x <= 2*i+2: break
    right.append(y[2*i+2])
b = len(left)
prev = y[0]
for i in range(b):
    if not left: break
    a =left.pop()
    sum += abs(prev - a)
    prev = a
    if not left : break
    a= left.pop(0)
    sum += abs(prev - a)
    prev = a
b = len(right)
prev = y[0]
for i in range(b):
    if not right: break
    a =right.pop()
    sum+= abs(prev-a)
    prev = a
    if not right : break
    a= right.pop(0)
    sum+= abs(prev-a)
    prev = a

if sum < suma : sum = suma
print(sum)