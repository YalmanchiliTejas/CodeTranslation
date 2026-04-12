from scipy.misc import comb

def f(n_str, k):
  while len(n_str) > 0 and n_str[0] == '0':
    n_str = n_str[1:]
  if len(n_str) < k:
    return 0
  if k == 1:
    return int(n_str[0]) + 9 * (len(n_str) - 1)
  else:
    return (int(n_str[0]) - 1) * f('9' * (len(n_str) - 1), k - 1) + f(n_str[1:], k - 1) + 9 ** k * (comb(len(n_str) - 1, k, exact=True) if len(n_str) > k else 0)

n = input()
k = int(input())

print(f(n, k))