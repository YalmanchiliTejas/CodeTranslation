def main(sample_file = ''):

    """ convenient functions
    # for i, a in enumerate(iterable)
    # q, mod = divmod(a, b)
    # divmod(x, y) returns the tuple (x//y, x%y)
    # Higher-order function: reduce(operator.mul, xyz_count, 1)
    # manage median(s) using two heapq https://atcoder.jp/contests/abc127/tasks/abc127_f
    """

    """convenient decorator
    # @functools.lru_cache():
    # to facilitate use of recursive function
        # ex:
        # from functools import lru_cache
        # import sys
        # sys.setrecursionlimit(10**9)
        # @lru_cache(maxsize=None)
        # def fib(n):
        #     if n < 2:
        #         return n
        #     return fib(n-1) + fib(n-2)
        # print(fib(1000))
    """
    
    # import numpy as np
    import sys
    sys.setrecursionlimit(10**7)
    from itertools import accumulate, combinations, permutations, product # https://docs.python.org/ja/3/library/itertools.html
    # accumulate() returns iterator! to get list: list(accumulate())
    from math import factorial, ceil, floor, sqrt
    def factorize(n):
        """return the factors of the Arg and count of each factor
        
        Args:
            n (long): number to be resolved into factors
        
        Returns:
            list of tuples: factorize(220) returns [(2, 2), (5, 1), (11, 1)]
        """
        fct = []  # prime factor
        b, e = 2, 0  # base, exponent
        while b * b <= n:
            while n % b == 0:
                n = n // b
                e = e + 1
            if e > 0:
                fct.append((b, e))
            b, e = b + 1, 0
        if n > 1:
            fct.append((n, 1))
        return fct
    def combinations_count(n, r):   
        """Return the number of selecting r pieces of items from n kinds of items.
        
        Args:
            n (long): number
            r (long): number
        
        Raises:
            Exception: not defined when n or r is negative
        
        Returns:
            long: number
        """
        # TODO: How should I do when n - r is negative?
        if n < 0 or r < 0:
            raise Exception('combinations_count(n, r) not defined when n or r is negative')
        if n - r < r: r = n - r
        if r < 0: return 0
        if r == 0: return 1
        if r == 1: return n
        numerator = [n - r + k + 1 for k in range(r)]
        denominator = [k + 1 for k in range(r)]
        for p in range(2,r+1):
            pivot = denominator[p - 1]
            if pivot > 1:
                offset = (n - r) % p
                for k in range(p-1,r,p):
                    numerator[k - offset] /= pivot
                    denominator[k] /= pivot
        result = 1
        for k in range(r):
            if numerator[k] > 1:
                result *= int(numerator[k])
        return result
    def combinations_with_replacement_count(n, r):
        """Return the number of selecting r pieces of items from n kinds of items allowing individual elements to be repeated more than once.
        
        Args:
            n (long): number
            r (long): number
        
        Raises:
            Exception: not defined when n or r is negative
        
        Returns:
            long: number
        """
        if n < 0 or r < 0:
            raise Exception('combinations_with_replacement_count(n, r) not defined when n or r is negative')
        elif n == 0:
            return 1
        else:
            return combinations_count(n + r - 1, r)
    from bisect import bisect_left, bisect_right
    from collections import deque, Counter, defaultdict # https://docs.python.org/ja/3/library/collections.html#collections.deque
    from heapq import heapify, heappop, heappush, heappushpop, heapreplace,nlargest,nsmallest # https://docs.python.org/ja/3/library/heapq.html
    from copy import deepcopy, copy # https://docs.python.org/ja/3/library/copy.html
    import operator
    from operator import itemgetter #sort 
    # ex1: List.sort(key=itemgetter(1))
    # ex2: sorted(tuples, key=itemgetter(1,2))
    from functools import reduce, lru_cache
    def chmin(x, y):
        """change minimum
        if x > y, x = y and return (x, True).
        convenient when solving problems of dp[i]
        
        Args:
            x (long): current minimum value
            y (long): potential minimum value
        
        Returns:
            (x, bool): (x, True) when updated, else (x, False)
        """
        if x > y:
            x = y
            return (x, True)
        else:
            return (x, False)
    def chmax(x, y):
        """change maximum
        if x < y, x = y and return (x, True).
        convenient when solving problems of dp[i]
        
        Args:
            x (long): current maximum value
            y (long): potential maximum value
        
        Returns:
            (x, bool): (x, True) when updated, else (x, False)
        """
        if x < y:
            x = y
            return (x, True)
        else:
            return (x, False)

    from fractions import gcd # Deprecated since version 3.5: Use math.gcd() instead.
    def gcds(numbers):
        return reduce(gcd, numbers)
    def lcm(x, y):
        return (x * y) // gcd(x, y)
    def lcms(numbers):
        return reduce(lcm, numbers, 1)
    def make_divisors(n, reversed=False):
        """create list of divisors
        
        Args:
            number (int): number from which list of divisors is created
            reversed (bool, optional): ascending order if False. Defaults to False.
        
        Returns:
            list: list of divisors
        """
        divisors = set()
        for i in range(1, int(n**0.5)+1):
            if n % i == 0:
                divisors.add(i)
                divisors.add(n//i)
        return sorted(list(divisors),reverse=reversed)
    
    # first create factorial_list
    # fac_list = mod_factorial_list(n)
    INF = 10 ** 18
    MOD = 10 ** 9 + 7
    modpow = lambda a, n, p = MOD: pow(a, n, p) # Recursive function in python is slow!
    def modinv(a, p = MOD):
        # evaluate reciprocal using Fermat's little theorem:
        # a**(p-1) is identical to 1 (mod p) when a and p is coprime
        return modpow(a, p-2, p)
    def modinv_list(n, p = MOD):
        if n <= 1:
            return [0,1][:n+1]
        else:
            inv_t = [0,1]
            for i in range(2, n+1):
                inv_t += [inv_t[p % i] * (p - int(p / i)) % p]
            return inv_t
    def modfactorial_list(n, p = MOD):
        if n == 0:
            return [1]
        else:
            l = [0] * (n+1)
            tmp = 1
            for i in range(1, n+1):
                tmp = tmp * i % p
                l[i] = tmp
            return l
    def modcomb(n, k, fac_list = [], p = MOD):
        # fac_list = modfactorial_list(100)
        # print(modcomb(100, 5, modfactorial_list(100)))
        from math import factorial
        if n < 0 or k < 0 or n < k: return 0
        if n == 0 or k == 0: return 1
        if len(fac_list) <= n:
            a = factorial(n) % p
            b = factorial(k) % p
            c = factorial(n-k) % p
        else:
            a = fac_list[n]
            b = fac_list[k]
            c = fac_list[n-k]
        return (a * modpow(b, p-2, p) * modpow(c, p-2, p)) % p
    def modadd(a, b, p = MOD):
        return (a + b) % MOD
    def modsub(a, b, p = MOD):
        return (a - b) % p
    def modmul(a, b, p = MOD):
        return ((a % p) * (b % p)) % p
    def moddiv(a, b, p = MOD):
        return modmul(a, modpow(b, p-2, p))

    class UnionFindTree:
        """union find tree class
        TODO: fix this description...
        how to use (example):
        >>  uf = UnionFindTree(N) 
        >>  if uf.find_root(a) == uf.find_root(b):
        >>      do something
        >>  else:
        >>      do something
        >>      uf.unite(a, b)
        """
        def __init__(self, N):
            self.root = [-1] * (N+1)
            self.rank   = [0]  * (N+1)
            self.connected_num = [1] * (N+1)
    
        def find_root(self,x):
            root = self.root
            while root[x] != -1:
                x = root[x]
            return x
    
        def unite(self,x,y):
            root = self.root
            rank = self.rank
            connected_num = self.connected_num
            find_root = self.find_root
    
            rx = find_root(x)
            ry = find_root(y)
            if rx != ry:
                if rank[rx] < rank[ry]:
                    root[rx] = ry
                    rx,ry = ry,rx
                else:
                    if rank[rx] == rank[ry]:
                        rank[rx] += 1
                    root[ry] = rx       
                connected_num[rx] += connected_num[ry]

    # Graph: https://en.wikipedia.org/wiki/Directed_graph
    # Bellman-Ford: O(|V||E|). Use this if there exists an edge with negative length in the graph
    # After N steps, the shortest path has converded if there doesn't exist an cycle of edges with negative
    # Watch out: d[N] == d[2*N] doesn't necessarily mean the graph doesn't have negative cycle
    # ref: https://www.youtube.com/watch?v=1Z6ofKN03_Y

    def BellmanFord(N, M, ABC, vertex_start, vertex_end, value_if_inf = -1, find_shortest = False):
        """to calculate furthest or shortest length between vertex_start and vertex_end using BellmanFord algorithm
        
        Args:
            N (int): number of vertices
            M (int): number of edges
            ABC (list): [(ai, bi, ci) for _ in range(N)] where i-th edge is directed from vertex ai to vertex bi and the length is ci 
            vertex_start (int): start vertex. usually use 0.
            vertex_end (int): end vertex. usually use N-1.
            value_if_inf (int or string as you like, optional): value you want when the furthest (or shortest) distance is infinite (or -infinite). Defaults to -1.
            find_shortest (bool, optional): choose False to find furthest path. Defaults to False.
        
        Returns:
            int or string: normally int (but can be str if you set value_if_inf to str)
            
        Example:
                N, M, P = R()
                ABC = [R() for _ in range(M)]
                ABC = [(a-1, b-1, c-P) for a, b, c in ABC]
                print(BellmanFord(N, M, ABC, 0, N-1, value_if_inf = 'inf'))

        """

        def make_reachable_list(N, M, ABC, vertex_start, vertex_end):
            reachable_to_direct = defaultdict(list)
            reachable_from_direct = defaultdict(list)
            reachable_from_start = [False] * N
            reachable_to_end = [False] * N
            reachable_from_start[vertex_start] = True
            reachable_to_end[vertex_end] = True
            reachable_from_both_sides = [False] * N
            dfs_from_start = []
            dfs_to_end = []
            for a, b, c in ABC:
                reachable_to_direct[a].append(b)
                reachable_from_direct[b].append(a)
                if a == vertex_start:
                    dfs_from_start.append(b)
                    reachable_from_start[b] = True
                if b == vertex_end:
                    dfs_to_end.append(a)
                    reachable_to_end[a] = True
            while dfs_from_start:
                v = dfs_from_start.pop()
                for i in reachable_to_direct[v]:
                    if not reachable_from_start[i]:
                        reachable_from_start[i] = True
                        dfs_from_start.append(i)
            while dfs_to_end:
                v = dfs_to_end.pop()
                for i in reachable_from_direct[v]:
                    if not reachable_to_end[i]:
                        reachable_to_end[i] = True
                        dfs_to_end.append(i)
            for i in range(N):
                reachable_from_both_sides[i] = reachable_from_start[i] and reachable_to_end[i]
            return reachable_from_both_sides
        
        reachable_from_both_sides = make_reachable_list(N, M, ABC, vertex_start, vertex_end)
        
        if find_shortest:
            dist = [INF for i in range(N)]
        else:
            dist = [-INF for i in range(N)]
        
        dist[vertex_start] = 0
        for i in range(N):
            updated = False
            for a, b, c in ABC:
                if not reachable_from_both_sides[a]:
                    continue
                elif find_shortest:
                    update_condition = dist[a] + c < dist[b]
                else:
                    update_condition = dist[a] + c > dist[b]
                if dist[a] != INF and update_condition:
                    dist[b] = dist[a] + c
                    updated = True
                    if i == N-1:
                        return value_if_inf
            if not updated:
                break
        return dist[vertex_end]

    """ initialize variables and set inputs
    # initialize variables
        # to initialize list, use [0] * n
        # to initialize two dimentional array:
            # ex) [[0] * N for _ in range(N)]
            # ex2) dp = [[0] * (N+1) for _ in range(W*2)]
    # set inputs
        # put inputs between specific values (almost as quickly)
        # ex) S = [-INF] + [int(r()) for _ in range(A)] + [INF]
        # open(0).read() is sometimes useful:
        # ex) n, m, *x = map(int, open(0).read().split())
        #     min(x[::2]) - max(x[1::2])
        # ex2) *x, = map(int, open(0).read().split())
        #     don't forget to add comma after *x if only one variable is used
    # preprocessing
        # transpose = [x for x in zip(*data)]
        # ex) [[1, 2, 3], [4, 5, 6], [7, 8, 9]] => [(1, 4, 7), (2, 5, 8), (3, 6, 9)]
        # flat = [flatten for inner in data for flatten in inner]
        # ex) [[1, 2, 3], [4, 5, 6], [7, 8, 9]] => [1, 2, 3, 4, 5, 6, 7, 8, 9]
    # calculate and output
        # output pattern
        # ex1) print(*l) => when l = [2, 5, 6], printed 2 5 6
    """

    # functions to read input
    r = lambda: sys.stdin.readline().strip()
    r_int = lambda: int(r())
    r_float = lambda: float(r())
    R = lambda: list(map(int, r().split()))
    R_str = lambda: r().split()
    R_map = lambda: map(int, r().split())
    R_float = lambda: list(map(float, r().split()))
    R_tuple = lambda: tuple(map(int, r().split()))

    """ how to treat input
    # single int: int(r())
    # single string: r()
    # single float: float(r())
    # line int: R()
    # line string: r().split()
    # line (str, int, int): [j if i == 0 else int(j) for i, j in enumerate(r().split())]
    # lines int: [R() for _ in range(n)]
    """

    # for test
    if sample_file:
        sys.stdin = open(sample_file)
        
    # ----------------------------------
    # main

    # S, T = R_str()
    # A, B = R()
    # U = r()
    # if S == U:
    #     print(A-1,B)
    # else:
    #     print(A, B-1)
    
    # S = r()
    # print('x'*len(S))

    # N = r_int()
    # A = R()
    # A.sort()
    # temp = -1
    # for i in A:
    #     if temp == i:
    #         print('NO')
    #         return
    #     temp = i
    # print('YES')

    # N, K = R()
    # P = R()
    # Q = [(1+p)/2 for p in P]
    # now = sum(Q[:K])
    # ans = now
    # for i in range(0,N-K):
    #     ans = max(ans, now)
    #     now = now - Q[i] + Q[i+K]
    # else:
    #     ans = max(ans, now)
    # print(ans)
    
    N = r()
    s = r_int()

    l = [[9, 18, 27, 36, 45, 54, 63, 72, 81, 90, 99, 108, 117, 126, 135, 144, 153, 162, 171, 180, 189, 198, 207, 216, 225, 234, 243, 252, 261, 270, 279, 288, 297, 306, 315, 324, 333, 342, 351, 360, 369, 378, 387, 396, 405, 414, 423, 432, 441, 450, 459, 468, 477, 486, 495, 504, 513, 522, 531, 540, 549, 558, 567, 576, 585, 594, 603, 612, 621, 630, 639, 648, 657, 666, 675, 684, 693, 702, 711, 720, 729, 738, 747, 756, 765, 774, 783, 792, 801, 810, 819, 828, 837, 846, 855, 864, 873, 882, 891, 900], [0, 81, 243, 486, 810, 1215, 1701, 2268, 2916, 3645, 4455, 5346, 6318, 7371, 8505, 9720, 11016, 12393, 13851, 15390, 17010, 18711, 20493, 22356, 24300, 26325, 28431, 30618, 32886, 35235, 37665, 40176, 42768, 45441, 48195, 51030, 53946, 56943, 60021, 63180, 66420, 69741, 73143, 76626, 80190, 83835, 87561, 91368, 95256, 99225, 103275, 107406, 111618, 115911, 120285, 124740, 129276, 133893, 138591, 143370, 148230, 153171, 158193, 163296, 168480, 173745, 179091, 184518, 190026, 195615, 201285, 207036, 212868, 218781, 224775, 230850, 237006, 243243, 249561, 255960, 262440, 269001, 275643, 282366, 289170, 296055, 303021, 310068, 317196, 324405, 331695, 339066, 346518, 354051, 361665, 369360, 377136, 384993, 392931, 400950], [0, 0, 729, 2916, 7290, 14580, 25515, 40824, 61236, 87480, 120285, 160380, 208494, 265356, 331695, 408240, 495720, 594864, 706401, 831060, 969570, 1122660, 1291059, 1475496, 1676700, 1895400, 2132325, 2388204, 2663766, 2959740, 3276855, 3615840, 3977424, 4362336, 4771305, 5205060, 5664330, 6149844, 6662331, 7202520, 7771140, 8368920, 8996589, 9654876, 10344510, 11066220, 11820735, 12608784, 13431096, 14288400, 15181425, 16110900, 17077554, 18082116, 19125315, 20207880, 21330540, 22494024, 23699061, 24946380, 26236710, 27570780, 28949319, 30373056, 31842720, 33359040, 34922745, 36534564, 38195226, 39905460, 41665995, 43477560, 45340884, 47256696, 49225725, 51248700, 53326350, 55459404, 57648591, 59894640, 62198280, 64560240, 66981249, 69462036, 72003330, 74605860, 77270355, 79997544, 82788156, 85642920, 88562565, 91547820, 94599414, 97718076, 100904535, 104159520, 107483760, 110877984, 114342921, 117879300]]

    d = len(N)
    # current_digit = len_n
    ans = 0

    def func_select(d, s):
        if d < 0 or s < 0 or d < s:
            return 0
        elif s == 0:
            return 1
        elif d == 0:
            return 0
        return l[s-1][d-1]
    
    for i,n in enumerate(N):
        for nn in range(int(n)):
            if nn == 0:
                ans += func_select(d-1, s)
            else:
                ans += func_select(d-1, s-1)
        d = d - 1
        if n != '0':
            s = s - 1
        if d < s or s < 0:
            break
    else:
        ans += 1
    
    print(ans)

    # to finish code, use return instead of exit()
    # end of main
    # ----------------------------------

    """memo: how to use defaultdict of list
    # initialize
    Dic = defaultdict(list)
    # append / extend
    Dic[x].append(y)
    # three methods for loop: keys(), values(), items()
    for k, v in Dic.items():
    """
    
    """memo: how to solve binary problems
    # to make binary digits text
    >>> a = 5
    >>> bin_str_a = format(a, '#06b')
    >>> print(bin_str_a)
    0b0101 # first 2 strings (='0b') indicates it is binary
    """
    
    """memo: how to solve the problem
    creating simple test/answer
    greed
    simple dp
    graph
    """

if __name__ == '__main__':
    main()