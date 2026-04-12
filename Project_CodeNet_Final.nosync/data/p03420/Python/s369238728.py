# Problem D - Remainder Reminder

# input
N, K = map(int, input().split())

# initialization
class_count = 0

for b in range(1, N+1):
    count_1 = (N//b) * max(0, b-K)
    count_2 = max(0, (N % b + 1) - K)
    class_count += count_1 + count_2

# output
if K==0:
    class_count -= N
print(class_count)
