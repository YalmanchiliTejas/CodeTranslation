n = int(input())
h = list(map(int, input().split()))
count = 0
for i in range(1,n+1):
    exam = h[0:i]
    sorted_exam = sorted(exam)
    if exam[-1] == sorted_exam[-1]:
        count += 1
print(count)