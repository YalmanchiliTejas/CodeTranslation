N, X, M = map(int, input().split())

A = X
loop_end = N
loop = [A]
loop_set = set(loop)
loop_last = -1
for i in range(1, N):
	A = (A * A) % M
	if A in loop_set:
		loop_last = A
		loop_end = i
		break
	loop_set.add(A)
	loop.append(A)

total_head = 0
total_loop = 0
total_tail = 0

i = 0
while i < N:
	A = loop[i]
	if A == loop_last:
		break
	total_head += A
	loop_set.remove(A)
	i += 1

if loop_end < N:
	loop_len = loop_end - i
	loop_rest = (N - i) % loop_len
	loop_count = (N - i - loop_rest) // loop_len
	while i < loop_end:
		total_loop += loop[i]
		i += 1
	i += loop_len * (loop_count - 1)
	A = loop[-1]
	A = (A * A) % M
	while i < N:
		total_tail += A
		A = (A * A) % M
		i += 1
else:
	loop_count = 0

#print(total_head, total_loop, loop_count, total_tail)

print(total_head + total_loop * loop_count + total_tail)
