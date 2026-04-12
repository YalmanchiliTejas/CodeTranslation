class RhoSequence:
    """
    A_1 = start, A_{i+1} = f(A_i) で、かつA_i が一定の整数の範囲内に収まるような数列に対するクエリを処理するクラス

    例：A_1=3, f(x)=x*x%7 -> A_2=2, A_3=4, A_4=2, A_5=4, ...
    """

    def __init__(self, f, start, val_max, val_min=0):
        self.f = f
        self.start = start
        self.val_max = val_max
        self.val_min = 0

        width = val_max - val_min + 1
        n = [-1] * width
        n[start-val_min] = 1
        route = [start] # A_1 からループが見つかるまでA_iの値を格納するリスト
        loop_start_n = -1 # ループがどこから始まったか
        x = start
        for i in range(2, width):
            fx = f(x)
            if n[fx] != -1:
                loop_start_n = n[fx]
                break
            route.append(fx)
            n[fx] = i
            x = fx
        self.route = route
        self.route_before_loop = route[:loop_start_n-1]
        self.loop_start_n = loop_start_n
        self.cycle = self.route[loop_start_n-1:]
        self.cycle_length = len(self.cycle)
    
    def get_nth_value(self, n):
        """
        n番目の数 A_n を返す
        """
        if n < self.loop_start_n:
            # nがループ開始より前の場合
            return self.route_before_loop[n-1]
        
        n -= self.loop_start_n
        return self.cycle[n%self.cycle_length]

    def sum_until_n(self, n):
        """
        A_1 から A_n までの合計を返す
        """
        if n < self.loop_start_n:
            # nがループ開始より前の場合
            return sum(self.route_before_loop[:n])

        ret = sum(self.route_before_loop)
        n -= self.loop_start_n - 1
        n_loop = n // self.cycle_length
        ret += n_loop * sum(self.cycle)
        n -= n_loop * self.cycle_length
        ret += sum(self.cycle[:n])
        return ret

def main():
    N, X, M = map(int, input().split())

    rs = RhoSequence(lambda x: x*x%M, X, M-1, 0)

    # print(rs.get_nth_value(N))
    print(rs.sum_until_n(N))

if __name__ == '__main__':
    main()