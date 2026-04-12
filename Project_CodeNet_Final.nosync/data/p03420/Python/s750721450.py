# Problem D - Remainder Reminder

# input
N, K = map(int, input().split())

# initialization
class_count = 0
for i in range(1, N+1):
    c_1 = (N//i) * max(0, i-K)
    c_2 = max(0, (N%i + 1 - K))

    class_count += c_1 + c_2

if K==0:
    class_count -= N
# output
print(class_count)
