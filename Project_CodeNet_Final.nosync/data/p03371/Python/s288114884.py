a, b, c, x, y = map(int, input().split(" "))
answer = 0

if c*2 < a + b:
    #ABピザに変更するインセンティブが発生している
    if x > y:
        ab_needed = y
        if a < c*2:
            answer += (x-y)*a
        else:
            answer += (x-y)*2*c
    else:
        ab_needed = x
        if b < c*2:
            answer += (y-x)*b
        else:
            answer += (y-x)*2*c
    answer += ab_needed*2*c
else:
    answer += a*x + b*y

print(answer)
