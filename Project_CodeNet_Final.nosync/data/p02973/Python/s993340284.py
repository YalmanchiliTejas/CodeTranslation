from bisect import bisect_left

n = int( input() )
a = []
for i in range(n):
    a.append(int(input()))

min_stack = [a[-1]]

for i in range(2,n+1):
    if min_stack[-1] <= a[-i]:
        min_stack.append(a[-i])
    else:
        tmp = min_stack[bisect_left(min_stack, a[-i])]
        if tmp == a[-i]:
            min_stack[bisect_left(min_stack, a[-i]+1)] = a[-i]
        else:
            min_stack[bisect_left(min_stack, a[-i])] = a[-i]

print(len(min_stack))