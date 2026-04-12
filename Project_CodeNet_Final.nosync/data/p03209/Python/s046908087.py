n, x = map(int, input().split())

position = 2**(n+2)-3
result = 0
while x > 0:
    position = (position-1)//2
    if x == position*2+1:
        result += position + 1
        x = 0
    elif x == position+1:
        result += position//2 + 1
        x = 0
    elif x > position:
        x -= position
        result += position//2+1
    x -= 1
    position -= 1
print(result)