a,b,c,x,y = map(int, input().split())

answer = a * x + b * y

while (2*c) < (a+b):
    if x >= 1 and y >= 1:
        answer = answer +  (2*c) - (a+b)
        x -= 1
        y -= 1
    else:
        break

while (2*c) < a:
    if x >= 1:
        answer = answer + (2*c) -a
        x -= 1
    else:
        break

while (2*c) < b:
    if y >= 1:
        answer = answer + (2*c) -b
        y -= 1
    else:
        break
print(answer)