N = int(input())
inputs = list(map(int, input().split(" ")))
p = 1
i = 2
for x in inputs[1:]:
    Max = max(inputs[0:i])
    p = p + 1 if x == Max else p
    i=i+1
print(p)