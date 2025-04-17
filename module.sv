module top;

   import "DPI-C" function void dpi_input(input logic [3:0][31:0] sv_logic_vec_a,  input int int_a[]) ;
   import "DPI-C" function void dpi_output(output logic [3:0][31:0] sv_logic_vec_a_out);

   logic [3:0][31:0]          sv_logic_vec_a;
   int                        int_a[4];
   logic [3:0][31:0]          sv_logic_vec_a_out;

   initial begin
      $display("\nHello from SystemVerilog!");
      for (int index=0; index < 4; index++)
        begin
           sv_logic_vec_a[index] = $urandom();
           int_a[index]          = index;
           $display("sv_logic_vec_a[%2d]=%x, int_a[%2d]=%d", index, sv_logic_vec_a[index], index, int_a[index]);
        end

      dpi_input(sv_logic_vec_a, int_a);
      dpi_output(sv_logic_vec_a_out);

      $display("\nHello from SystemVerilog!");
      for (int index=0; index < 4; index++)
        $display("sv_logic_vec_a_out[%2d]=%x", index, sv_logic_vec_a_out[index]);

      $finish(0);
   end
   
endmodule

