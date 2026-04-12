
import bisect


def main():
  n = int(input())
  a = [int(input()) for _ in range(n)]

  tail = []
  len_tail = 0
  for ai in a:
    idx = bisect.bisect_right(tail, -ai, lo=0, hi=len_tail) 
    if idx == len_tail:
      tail.append(-ai)
      len_tail += 1
    else:
      tail[idx] = - ai

  print(len_tail )


if __name__ == "__main__":
  main()