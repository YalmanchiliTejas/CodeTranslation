n, x = map(int, input().split())

answer = 0
red = x

searching_index = n
while red > 0:
    for i in reversed(range(searching_index + 1)):
        length = 2**(i + 2) - 3
        if red >= length:
            if red >= length + 1:
                answer += 1
                red -= 1
            searching_index = i
            answer += 2**(i+1) - 1
            red -= length
            break
        red -= 1

print(answer)