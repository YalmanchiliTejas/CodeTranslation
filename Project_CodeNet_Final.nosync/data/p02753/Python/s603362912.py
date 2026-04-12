N = list(input())

answer = 'No'
count = N.count('A')
if count != 3 and count != 0:
    answer = 'Yes'

print(answer)
