n = int(input())
value = n*800
down = n/15

if(int(down) >= 1):
    print(value - (int(down) * 200))
else:
    print(value)