import java.util.*;
public class Main {
    static int[] arr =new int[6];
    
    public static void nearestLift(int req){
        int min=Math.abs(arr[0]-req);
        int lftnum=0;
        
        for(int i=1;i<arr.length;i++){
           if(Math.abs(arr[i]-req)<min){
               min=Math.abs(arr[i]-req);
               lftnum=i;
           }
        }
        System.out.println("Nearest lift number :"+(lftnum+1));
        
    }
    
    public static void main(String[] args) {
        // arr[0]=3;
        // arr[1]=0;
        // arr[2]=6;
        // arr[3]=12;
        // arr[4]=10;
        // arr[5]=11;
        Scanner sc =new Scanner(System.in);
        
        System.out.println("Enter number of testcases");
        
        int n=sc.nextInt();
        for(int i=0;i<6;i++){
                System.out.println("Initialize the " + (i+1) + " lift position.");
                arr[i]=sc.nextInt();
            }
        
        while(n!=0){
         System.out.println("Enter your floor number");
        int req=sc.nextInt(); 
        nearestLift(req);
            n--;
        }
    }
}