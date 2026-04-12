num = int(input())
input_line = input().split()

law = 10 ** 9 + 7
num_list = [int(input_line[i])%law for i in range(num)]

sigma = 0
temp_sum = 0
for j in range(num):
	temp_sum += num_list[j]

for i in range(num):
	num_a = num_list[i]
	temp_sum -= num_a
	sigma += num_a * temp_sum


sigma %= law
print(sigma)