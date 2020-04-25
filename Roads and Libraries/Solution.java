import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the roadsAndLibraries function below.
    static void dfs(int[][] g,int [] v,int i)
        {
        int j;
        v[i]=1;
        for(j=0;j<g[0].length;j++){
            if((v[j]==0)&&g[i][j]==1)
            dfs(g,v,j);
        }
    }
    static int comp(int[][] g,int n)
    {
        int visited[]=new int[n];
        int c=0,i;
        for(i=0;i<n;i++){
            visited[i]=0;
        }
         for(i=0;i<n;i++){
            if(visited[i]==0){
                c++;
                dfs(g,visited,i);
            }
        }
        return c;
    }
    static long roadsAndLibraries(int n, int c_lib, int c_road, int[][] cities) {
    long cost=0;
    if(c_road>c_lib){
    
    cost=n*c_lib;
    }
  else{
      int g[][]=new int[n][n];
      int i,j,m,k;
      for(i=0;i<n;i++){
          for(j=0;j<n;j++){
              g[i][j]=0;
          }}
      for(i=0;i<=cities[0].length;i++){
          m=cities[i][0];
          k=cities[i][1];
          g[m-1][k-1]=1;
          g[k-1][m-1]=1;

      } 
      for(i=0;i<n;i++){
          for(j=0;j<n;j++){
              System.out.print(g[i][j]);
          }
          System.out.println();}

        int com=comp(g,n); 
        System.out.println(com);
        cost=com*c_lib+(n-com)*c_road; 
      }
      return cost;
  }




    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int q = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int qItr = 0; qItr < q; qItr++) {
            String[] nmC_libC_road = scanner.nextLine().split(" ");

            int n = Integer.parseInt(nmC_libC_road[0]);

            int m = Integer.parseInt(nmC_libC_road[1]);

            int c_lib = Integer.parseInt(nmC_libC_road[2]);

            int c_road = Integer.parseInt(nmC_libC_road[3]);

            int[][] cities = new int[m][2];

            for (int i = 0; i < m; i++) {
                String[] citiesRowItems = scanner.nextLine().split(" ");
                scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

                for (int j = 0; j < 2; j++) {
                    int citiesItem = Integer.parseInt(citiesRowItems[j]);
                    cities[i][j] = citiesItem;
                }
            }

            long result = roadsAndLibraries(n, c_lib, c_road, cities);

            bufferedWriter.write(String.valueOf(result));
            bufferedWriter.newLine();
        }

        bufferedWriter.close();

        scanner.close();
    }
}
