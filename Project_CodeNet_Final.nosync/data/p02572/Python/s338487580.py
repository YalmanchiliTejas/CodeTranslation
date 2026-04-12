N = int(input())
As = list(map(int, input().split(" ")))

rule = 1000000007
s = 0
list_sum = sum(As[1:])
if list_sum >= rule:
    list_sum = list_sum % rule

for i in range(len(As) - 1):
    s += As[i] * list_sum
    if s >= rule:
        s = s % rule
    list_sum -= As[i+1]
    if list_sum < 0:
        list_sum += rule
print(s)