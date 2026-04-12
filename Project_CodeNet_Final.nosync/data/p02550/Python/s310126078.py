def main():
	N, X, M = [int(a) for a in input().split(" ")]
	used_r = [0] * M
	r = [-1, X]
	used_r[X] = 1
	loop_start_elm = -1
	loop_start_n_2 = -1
	for i in range(M):
		A = r[-1]
		B = (A * A) % M
		if used_r[B] == 0:
			r.append(B)
			used_r[B] = 1
		else:
			loop_start_elm = B
			loop_start_n_2 = i + 2
			break
	loop_start_n = r.index(B)

	s1 = sum(r[:loop_start_n]) + 1
	s2 = sum(r[loop_start_n:loop_start_n_2])
	loop_len = loop_start_n_2 - loop_start_n
	loop_n = int((N - loop_start_n + 1) / loop_len)
	rest_n = (N - loop_start_n + 1) % loop_len
	s3 = sum(r[loop_start_n:(loop_start_n + rest_n)])
	print(s1 + s2 * loop_n + s3)

main()

