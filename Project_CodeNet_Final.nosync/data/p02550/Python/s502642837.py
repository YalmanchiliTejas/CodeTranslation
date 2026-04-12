def main():
    N, X, M = [int(s) for s in input().split()]

    sums = [0]
    s = 0
    seen = {}
    for i in range(N):
        if X in seen:
            previ = seen[X]
            # repeats from previ, ... i-1
            seq_length = i - previ
            remaining_full = (N - i) // seq_length
            remaining_part = (N - i) - remaining_full * seq_length
            s += (sums[-1] - sums[-seq_length-1]) * remaining_full
            s += sums[remaining_part-seq_length-1] - sums[-seq_length-1]
            print(s)
            return
        s += X
        sums.append(s)
        seen[X] = i

        X = X * X % M

    print(s)

main()

