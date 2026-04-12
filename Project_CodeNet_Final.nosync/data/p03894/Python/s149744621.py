n, q = [int(item) for item in input().split()]
ball = [0] * n
ball[0] = 1
ball[1] = 1
place = 0
for i in range(q):
    a, b = [int(item) - 1 for item in input().split()]
    if a == place:
        place = b
    elif b == place:
        place = a
    ball[a], ball[b] = ball[b], ball[a]
    if place - 1 >= 0:
        ball[place - 1] = 1
    if place + 1 < n:
        ball[place + 1] = 1
print(sum(ball))